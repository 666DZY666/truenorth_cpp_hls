-------------------------------------------------------------------------------
-- Project    : 
-------------------------------------------------------------------------------
-- File       : 
-- Author     : Andrei Basa
-- Created    : 
-- Standard   : VHDL'87
-------------------------------------------------------------------------------
-- Copyright (c) 2011 Infineon Technologies AG
-------------------------------------------------------------------------------
-- Revisions  :
-- Date        Version  Author  Description
-- 
-------------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;


ENTITY rocket_gen_loop IS
   GENERIC(
        t_width_g             : integer :=16
   );
   PORT(
        sys_rst_n_i         : in std_logic; --fpga system reset, low active   
        sys_clk_i           : in std_logic; --100 MHz system clock derived from fpga oscilator
        
        fire_en_time_i      : in std_logic_vector(t_width_g-1 downto 0); --multiple of sys clk period (measured from rising edge of launch_en)
        detonation_en_time_i: in std_logic_vector(t_width_g-1 downto 0); --multiple of sys clk period (measured from rising edge of fire_en_o)
        
        launch_en_o         : out std_ulogic;
        fire_en_o           : out std_logic;
        detonation_o        : out std_logic 
        
   );
   
END rocket_gen_loop;

ARCHITECTURE rtl OF rocket_gen_loop IS

-----------------------------------------------------------------------------
-- internal signals:
----------------------------------------------------------------------------- 
type t_state_rocker is (WAIT_FOR_LAUNCH_EN, WAIT_FOR_FIRE_EN ,WAIT_FOR_DETONATION, DETONATION);
signal rocket_state_s : t_state_rocker;
signal rocket_next_state_s : t_state_rocker;

type t_fail_state is (Normal, Fail01, Fail10);
signal fail_state_s : t_fail_state;
signal fail_next_state_s : t_fail_state;

signal fire_en_s : std_logic;
signal detonation_s : std_logic;

signal cnt_s : unsigned(t_width_g-1 downto 0);
--signal launch_en_d1_s : std_logic;
signal failure_mode_sync_s : std_logic_vector(1 downto 0);
signal launch_en_s : std_logic;
signal failure_mode_s : std_logic_vector(1 downto 0);
signal loop_cnt_s : integer range 0 to 255;
signal trig_failure_mode_s : std_logic;
signal prev_was_01_s : std_logic;

BEGIN

-----------------------------------------------------------------------------
-- connect the outputs
----------------------------------------------------------------------------- 
launch_en_o <= launch_en_s;
fire_en_o <= fire_en_s;
detonation_o <= detonation_s;

-----------------------------------------------------------------------------
-- generate launch en in a loop 
----------------------------------------------------------------------------- 
  loop_cnt_p: process (sys_rst_n_i, sys_clk_i)
  begin  
    if sys_rst_n_i = '0' then                -- asynchronous reset (active low)
       loop_cnt_s <= 0;
       prev_was_01_s <= '0';
    elsif sys_clk_i'event and sys_clk_i = '1' then  -- rising clock edge
       if loop_cnt_s = 199 then
          loop_cnt_s <= 0;
       else
          loop_cnt_s <= loop_cnt_s + 1;
       end if;  
       if fail_state_s = Fail01 then
          prev_was_01_s <= '1';
       elsif fail_state_s = Fail10 then
          prev_was_01_s <= '0';
       end if;        
    end if;
  end process loop_cnt_p;


launch_en_s <= '1'when (loop_cnt_s >= 100) else '0';
trig_failure_mode_s <= '1' when (loop_cnt_s = 199) else '0';

-- synchronous part of the fsm failure mode
  p_fail_state: process (sys_rst_n_i, sys_clk_i)
  begin  -- process p_fsm_seq
    if sys_rst_n_i = '0' then                -- asynchronous reset (active low)
       fail_state_s <= Normal;
    elsif sys_clk_i'event and sys_clk_i = '1' then  -- rising clock edge
       fail_state_s <= fail_next_state_s;
    end if;
  end process p_fail_state;

-- asynchronous part of the fsm failure mode
  p_next_fail_state: process(trig_failure_mode_s, fail_state_s, prev_was_01_s)
  begin
     failure_mode_s <= "00";
     case fail_state_s is 
        when Normal =>
           failure_mode_s <= "00";
           if trig_failure_mode_s = '1' then
              if prev_was_01_s = '0' then
                 fail_next_state_s <= Fail01;
              else
                 fail_next_state_s <= Fail10;
              end if;   
           else
              fail_next_state_s <= Normal;
           end if;
        when Fail01 =>
           failure_mode_s <= "01";
           if trig_failure_mode_s = '1' then
              fail_next_state_s <= Normal;
           else
              fail_next_state_s <= Fail01;
           end if;
        when Fail10 =>
           failure_mode_s <= "10";
           if trig_failure_mode_s = '1' then
              fail_next_state_s <= Normal;
           else
              fail_next_state_s <= Fail10;
           end if;
        when others =>
           failure_mode_s <= "00";
     end case;
  end process p_next_fail_state;
  
-----------------------------------------------------------------------------
-- combinatorial logic
----------------------------------------------------------------------------- 
-- asynchronous part of the fsm
  p_next_state_rocket: process (rocket_state_s, failure_mode_sync_s, launch_en_s, cnt_s, fire_en_time_i, detonation_en_time_i)
  begin  -- process p_next_state
    -- default values:
    fire_en_s <= '0';
    detonation_s <= '0';
    -- signals depending on state
    case rocket_state_s is
      when WAIT_FOR_LAUNCH_EN => 
         fire_en_s <= '0';
         detonation_s <= '0';
         if cnt_s > 0 then 
            rocket_next_state_s <= WAIT_FOR_FIRE_EN;
         else
            rocket_next_state_s <= WAIT_FOR_LAUNCH_EN;
         end if; 
      when WAIT_FOR_FIRE_EN =>
         fire_en_s <= '0';
         detonation_s <= '0';
           if failure_mode_sync_s = "01" then --too late fire enable 
            if cnt_s = unsigned(fire_en_time_i) + 1 then
               rocket_next_state_s <= WAIT_FOR_DETONATION;
            else
               rocket_next_state_s <= WAIT_FOR_FIRE_EN;
            end if;
           else --normal mode
            if cnt_s = unsigned(fire_en_time_i) - 1 then
               rocket_next_state_s <= WAIT_FOR_DETONATION;
            else
               rocket_next_state_s <= WAIT_FOR_FIRE_EN;
            end if;
           end if; 
      when WAIT_FOR_DETONATION =>
         fire_en_s <= '1';
         detonation_s <= '0';
           if failure_mode_sync_s = "10" then --too early detonation 
            if cnt_s = (unsigned(fire_en_time_i) + unsigned(detonation_en_time_i) - 4) then
               rocket_next_state_s <= DETONATION;
            else
               rocket_next_state_s <= WAIT_FOR_DETONATION;
            end if;
           elsif failure_mode_sync_s = "01" then --compensate the too late fire en
            if cnt_s = (unsigned(fire_en_time_i) + unsigned(detonation_en_time_i) + 1) then
               rocket_next_state_s <= DETONATION;
            else
               rocket_next_state_s <= WAIT_FOR_DETONATION;
            end if;
           else
            if cnt_s = (unsigned(fire_en_time_i) + unsigned(detonation_en_time_i) - 1) then
               rocket_next_state_s <= DETONATION;
            else
               rocket_next_state_s <= WAIT_FOR_DETONATION;
            end if;
           end if;  
      when DETONATION =>
         fire_en_s <= '1';
         detonation_s <= '1';
         if launch_en_s = '0' then 
            rocket_next_state_s <= WAIT_FOR_LAUNCH_EN;
         else
            rocket_next_state_s <= DETONATION;
         end if;
      when others => 
        fire_en_s <= '0';
        detonation_s <= '0';
    end case;                    
  end process p_next_state_rocket;     

-----------------------------------------------------------------------------
-- sync logic
----------------------------------------------------------------------------- 
-- synchronous part of the fsm 
  p_rocket_fsm_seq: process (sys_rst_n_i, sys_clk_i)
  begin  -- process p_fsm_seq
    if sys_rst_n_i = '0' then                -- asynchronous reset (active low)
       rocket_state_s <= WAIT_FOR_FIRE_EN;
    elsif sys_clk_i'event and sys_clk_i = '1' then  -- rising clock edge
       rocket_state_s <= rocket_next_state_s;
    end if;
  end process p_rocket_fsm_seq;
  
  
--counter:
  p_cnt: process (sys_rst_n_i, sys_clk_i)
  begin  -- process p_fsm_seq
    if sys_rst_n_i = '0' then                -- asynchronous reset (active low)
       cnt_s <= (others => '0');
       --launch_en_d1_s <= '0';
       failure_mode_sync_s <= "00";
    elsif sys_clk_i'event and sys_clk_i = '1' then  -- rising clock edge
       --launch_en_d1_s <= launch_en_i;
       failure_mode_sync_s <= failure_mode_s;
       if launch_en_s = '1' then
          if cnt_s = (unsigned(fire_en_time_i) + unsigned(detonation_en_time_i) + 3) then
             cnt_s <= (unsigned(fire_en_time_i) + unsigned(detonation_en_time_i) + 3);
          else
             cnt_s <= cnt_s + 1;   
          end if;
       else
          cnt_s <= (others => '0');
       end if;
    end if;
  end process p_cnt;

  
END rtl;


