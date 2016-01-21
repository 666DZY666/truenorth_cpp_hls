----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 01/15/2016 10:34:44 AM
-- Design Name: 
-- Module Name: input_gen_sim - arch
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
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity input_gen_sim is

end input_gen_sim;

architecture arch of input_gen_sim is

-- testing input_gen
component input_gen is
  port (
        rst_i    : in std_logic;
        clk_i    : in std_logic;
        gen_o    : out std_logic_vector(0 downto 0)
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
i_DUT : input_gen
   PORT MAP(
        rst_i          => rst_i_s,         
        clk_i          => clk_i_s,
        gen_o          => open
        );

end arch;
