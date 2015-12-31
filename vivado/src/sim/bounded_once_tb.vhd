----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 10/07/2015 05:42:02 PM
-- Design Name: 
-- Module Name: bounded_once_test - Behavioral
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

use IEEE.NUMERIC_STD.ALL;

library UNISIM;
use UNISIM.VComponents.all;

entity bounded_once_test is
-- for observing in high-level testbench
    port(
         clk_in        : in  std_logic;
         spike_v_out   : out std_logic_vector ( 0 to 0 );
         drv_out       : out std_logic_vector ( 0 to 0 )
         );
end bounded_once_test;

architecture Behavioral of bounded_once_test is

    component bounded_once_debug_wrapper  -- add components to the test_bench
    port( 
        ap_clk      :   in  STD_LOGIC;
        ap_rst      :   in  STD_LOGIC;
        ap_start    :   in  STD_LOGIC;
        in1         :   in  STD_LOGIC_VECTOR (0 to 0);
        out1        :   out STD_LOGIC_VECTOR (0 to 0)
        );
    end component;
    
    component signal_generator -- add signal generator to the test bench
    port(   
         rst :   in std_logic;
         clk :   in std_logic;
         drv :   out std_logic_vector(0 downto 0);
         ap_rst_o   : out std_logic;
         ap_start_o : out std_logic
        );
    end component;
    
    --declare inputs and initialize them
--    signal clk         : std_logic := '0';
    signal reset       : std_logic := '0';
    signal reset_gen   : std_logic :=  not reset;
    signal in1         : std_logic_vector (0 downto 0) := "0";
    signal ap_start_in : std_logic := '0';
    -- declare outputs and initialize them

begin
    -- Instantiate monitor(mon) and signal generator (gen)
    mon: bounded_once_debug_wrapper PORT MAP (
          ap_clk => clk_in,
          ap_rst => reset,
          ap_start => ap_start_in,
          in1(0) => in1(0),
          out1(0) => spike_v_out(0)
        );
               
    gen: signal_generator port map (
          rst => reset_gen,
          clk => clk_in,
          drv(0) => in1(0)
         );
        
    -- generate correct reset behavior
    res_proc: process
    begin         
         reset <= '1';
         wait for 100 ns;
         reset <= '0';
         wait for 3 ns;
         ap_start_in <= '1';
         wait for 2000ms;
    end process;

drv_out(0) <= in1(0);

end Behavioral;
