----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/14/2016 07:48:55 PM
-- Design Name: 
-- Module Name: ip_debug_sim - Behavioral
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
library UNISIM;
use UNISIM.VComponents.all;

entity ip_debug_sim is

end ip_debug_sim;

architecture Behavioral of ip_debug_sim is

-- testing ip_debug_bd
component ip_debug_bd_wrapper is
  port (
    clk_i : in STD_LOGIC;
    rst_i : in STD_LOGIC;
    spike_V : out STD_LOGIC_VECTOR ( 0 to 0 )
  );
end component;

signal clk_i_s : std_logic := '0';
signal rst_i_s : std_logic := '0';

begin

clk_i_s <= NOT(clk_i_s) after 0.05 us;
rst_i_s <= '0', '1' after 33 us;


------------------------------------------------------------------
-- port mapping
------------------------------------------------------------------ 
i_DUT : ip_debug_bd_wrapper
   PORT MAP(
        rst_i          => rst_i_s,         
        clk_i          => clk_i_s,
        spike_V        => open
        );

end Behavioral;
