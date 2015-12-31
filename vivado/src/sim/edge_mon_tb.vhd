----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 08/25/2015 02:16:41 AM
-- Design Name: 
-- Module Name: edge_mon_tb - Behavioral
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

entity edge_mon_tb is
--  Port ( );
end edge_mon_tb;

architecture Behavioral of edge_mon_tb is


    COMPONENT edge_mon_bd_wrapper  --'test' is the name of the module needed to be tested.
    --just copy and paste the input and output ports of your module as such. 
    PORT(
        ap_clk              :   in STD_LOGIC;
        ap_rst              :   in STD_LOGIC;
        ap_start            :   in STD_LOGIC;
        in1                 :   in STD_LOGIC;
        out1                :   out STD_LOGIC_VECTOR(0 to 0)
        );
    END COMPONENT;
       --declare inputs and initialize them
       signal ap_clk_s      : std_logic := '0';
       signal ap_rst_s      : std_logic := '0';
       signal ap_start_s    : std_logic := '0';
       signal in1_s         : std_logic := '0';
       signal out1_s        : std_logic_vector (0 to 0);
      
       --declare outputs and initialize them
       -- Clock period definitions
       constant clk_period : time := 80 ns;

begin

    -- Instantiate the Unit Under Test (UUT)
uut: edge_mon_bd_wrapper PORT MAP (
        ap_clk          =>  ap_clk_s,
        ap_rst          =>  ap_rst_s, 
        ap_start        =>  ap_start_s, 
        in1             =>  in1_s, 
        out1            =>  out1_s
    ); 
    
    -- Clock process definitions( clock with 50% duty cycle is generated here.
      clk_process :process
      begin
           ap_clk_s <= '0';
           wait for clk_period/2;  --for 0.5 ns signal is '0'.
           ap_clk_s <= '1';
           wait for clk_period/2;  --for next 0.5 ns signal is '1'.
      end process;
      
    -- Reset stimulus process
         res_proc: process
          begin         
               ap_rst_s <= '1';
               wait for 35 ns;
               ap_rst_s <= '0';
               wait for 3 ns;
               ap_start_s <= '1';
               wait for 3ms;
         end process;
           
         -- Input Stimulus process
         in_proc: process
          begin         
               in1_s <= '0';
               wait for 360 ns;
               in1_s <= '1';
               wait for 240 ns;
               in1_s <= '0';
               wait for 560 ns;
               in1_s <= '1';
               wait for 240 ns;
               in1_s <= '0';
               wait for 3ms;
         end process;


end Behavioral;
