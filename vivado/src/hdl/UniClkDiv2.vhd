----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 06/16/2015 04:08:38 PM
-- Design Name: 
-- Module Name: UniClkDiv2 - Behavioral
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
--library UNISIM;
--use UNISIM.VComponents.all;

entity clk_gen is
    Port ( clk_i : in STD_LOGIC;
           clk_o : out STD_LOGIC;
           div_val_i : in STD_LOGIC_VECTOR (23 downto 0));
end clk_gen;

architecture Behavioral of clk_gen is

signal counter,divide : integer := 0;

begin
    
    divide <= to_integer(unsigned(div_val_i));

    process(clk_i)
    begin
    if (rising_edge(clk_i)) then
        if (counter < divide/2-1) then
            counter <= counter + 1 ;
            clk_o <= '1';
        elsif (counter < divide-1) then
            counter <= counter + 1 ;
            clk_o <= '0';
        else 
            clk_o <= '1';
            counter <= 0 ;
        end if;
    end if;
end process;

end Behavioral;
