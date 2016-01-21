----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/14/2016 03:51:24 PM
-- Design Name: 
-- Module Name: input_gen - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.std_logic_unsigned.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity input_gen is
  Port(
       rst_i    : in std_logic;
       clk_i    : in std_logic;
       
       gen_o    : out std_logic_vector(0 downto 0)
       );
end input_gen;

architecture rtl of input_gen is

type t_state_gen is (s0, s1, s2, s3, s4);
signal gen_state_s          :   t_state_gen := s0;

signal      gen_o_s         :   std_logic_vector(0 downto 0); 
constant    period_length   :   integer := 10;
signal      period_cnt_s    :   integer range 0 to period_length;

begin
-----------------------------------------------------------------------------
-- connect the outputs
----------------------------------------------------------------------------- 
gen_o <= gen_o_s;

-----------------------------------------------------------------------------
-- count to a period_length
----------------------------------------------------------------------------- 
period_cnt_p: process(rst_i, clk_i)
begin
    if rst_i = '0' then
        period_cnt_s <= 0;
    elsif rising_edge(clk_i) then
        if period_cnt_s = period_length then
            period_cnt_s <= 0;
        else 
            period_cnt_s <= period_cnt_s + 1;
        end if;
     end if;
end process period_cnt_p;

state_p: process(gen_state_s, rst_i, clk_i)
begin
    if(rst_i = '0') then
        gen_state_s <= s0;
    elsif rising_edge(clk_i) then
        case gen_state_s is
            when s0 =>
                if period_cnt_s = period_length then 
                    gen_state_s <= s1;
                    gen_o_s <= "0";
                else
                    gen_state_s <= s0;
                    gen_o_s <= "0";
                end if;
            when s1 =>
                if period_cnt_s = period_length then 
                    gen_state_s <= s2;
                    gen_o_s <= "0";
                elsif period_cnt_s < 1 then
                    gen_o_s <= "1";
                    gen_state_s <= s1;
                else
                    gen_o_s <= "0";
                    gen_state_s <= s1;
                end if;
            when s2 =>
                if period_cnt_s = period_length then 
                    gen_state_s <= s3;
                    gen_o_s <= "0";
                elsif period_cnt_s < 2 then
                    gen_o_s <= "1";
                    gen_state_s <= s2;
                else
                    gen_o_s <= "0";
                    gen_state_s <= s2;
                end if;
            when s3 =>
                if period_cnt_s = period_length then 
                    gen_state_s <= s4;
                    gen_o_s <= "0";
                elsif period_cnt_s < 3 then
                    gen_o_s <= "1";
                    gen_state_s <= s3;
                else
                    gen_o_s <= "0";
                    gen_state_s <= s3;
                end if;
            when s4 =>
                if period_cnt_s = period_length then 
                    gen_state_s <= s1;
                    gen_o_s <= "0";
                elsif period_cnt_s < 4 then
                    gen_o_s <= "1";
                    gen_state_s <= s4;
                else
                    gen_o_s <= "0";
                    gen_state_s <= s4;
                end if;
        end case;
    end if;
end process state_p;

end rtl;
