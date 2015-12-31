----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09/10/2015 10:04:08 AM
-- Design Name: 
-- Module Name: rocket_std_top_tb - Behavioral
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

entity rocket_top_tb is

end rocket_top_tb;

architecture Behavioral of rocket_top_tb is
--component declaration:

-- testing rocket_stl_bd
component rocket_stl_bd_wrapper IS
  port (
        clk_div : out STD_LOGIC;
        clk_i : in STD_LOGIC;
        detonation_en : out STD_LOGIC;
        fire_en : out STD_LOGIC;
        launch_en_mon : out STD_LOGIC;
        mon_o : out STD_LOGIC_VECTOR ( 0 to 0 );
        mon_o_scope : out STD_LOGIC_VECTOR ( 0 to 0 );
        rst_n_i : in STD_LOGIC
      );
end component;

-- testing bounded_once 
-- component bounded_once_test is
--     port(
--         clk_in        : in std_logic;
--         spike_v_out   : out std_logic_vector ( 0 to 0 );
--         drv_out       : out std_logic_vector ( 0 to 0 )
--         );
-- end component;

signal sys_clk_s : std_logic := '0';
signal sys_rst_n_s : std_logic;

begin
------------------------------------------------------------------
-- clock and reset generation
------------------------------------------------------------------ 
sys_clk_s <= NOT(sys_clk_s) after 0.05 us;
sys_rst_n_s <= '0', '1' after 33 us;

------------------------------------------------------------------
-- port mapping
------------------------------------------------------------------ 
i_DUT : rocket_stl_bd_wrapper
   PORT MAP(
        rst_n_i         => sys_rst_n_s,         
        clk_i           => sys_clk_s,
        
        fire_en        => open,
        detonation_en  => open,
        launch_en_mon  => open,
        clk_div        => open,
        mon_o          => open, 
        mon_o_scope    => open
        );


-- b_once_test : bounded_once_test 
--    PORT MAP(
--         clk_in          => sys_clk_s,
--         spike_v_out     => open,
--         drv_out         => open
--         );
        
end Behavioral;
