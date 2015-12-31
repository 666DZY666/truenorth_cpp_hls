library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
use ieee.std_logic_unsigned.all;

ENTITY SR_ff IS
   
   PORT(
        sys_rst_n_i         : in std_ulogic; --fpga system reset, low active   
        sys_clk_i           : in std_ulogic; --100 MHz system clock derived from fpga oscilator
        Set_i               : in std_ulogic;
        Reset_i             : in std_ulogic;
        
        Q_o                 : out std_ulogic
        
        
   );
   
END SR_ff;

ARCHITECTURE rtl OF SR_ff IS

signal set_p_s, reset_p_s : std_ulogic;
signal set_d1_s, set_d2_s : std_ulogic;
signal reset_d1_s, reset_d2_s : std_ulogic;

begin

--build the pulses

reg_p : process(sys_rst_n_i, sys_clk_i)
begin
   if sys_rst_n_i = '0' then 
      set_d1_s <= '0';
      set_d2_s <= '0';
      reset_d1_s <= '0';
      reset_d2_s <= '0';
   elsif rising_edge(sys_clk_i) then
      set_d1_s <= set_i;
      set_d2_s <= set_d1_s;
      reset_d1_s <= reset_i;
      reset_d2_s <= reset_d1_s;          
   end if;
end process reg_p;

set_p_s <= set_d1_s AND NOT(set_d2_s); 
reset_p_s <= reset_d1_s XOR reset_d2_s;


SR_ff_p : process(sys_rst_n_i, sys_clk_i)
begin
   if sys_rst_n_i = '0' then 
      Q_o <= '0';
   elsif rising_edge(sys_clk_i) then
      if Set_p_s = '1' then
         Q_o <= '1';
      elsif Reset_p_s = '1' then
         Q_o <= '0';
      end if;           
   end if;
end process SR_ff_p;

end architecture;
