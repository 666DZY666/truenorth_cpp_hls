----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 08/24/2015 11:07:55 PM
-- Design Name: 
-- Module Name: bounded_hist_tb - Behavioral
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

LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.all;


-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity bounded_hist_tb is
--  Port ( );
end bounded_hist_tb;

architecture Behavioral of bounded_hist_tb is

  COMPONENT bounded_hist_bd_wrapper  --'test' is the name of the module needed to be tested.
--just copy and paste the input and output ports of your module as such. 
    PORT( 
        ap_clk      :   in STD_LOGIC;
        ap_ready    :   out STD_LOGIC;
        ap_rst      :   in STD_LOGIC;
        ap_start    :   in STD_LOGIC;
        in1         :   in STD_LOGIC;
        spike_V     :   out STD_LOGIC_VECTOR (0 to 0)
        );
    END COMPONENT;
    --declare inputs and initialize them
    signal clk : std_logic := '0';
    signal reset : std_logic := '0';
    signal in1 : std_logic := '0';
    signal ap_start_in : std_logic := '0';
    signal spike_V_out : std_logic_vector (0 to 0);
    --declare outputs and initialize them
    -- Clock period definitions
    constant clk_period : time := 80 ns;
begin
    -- Instantiate the Unit Under Test (UUT)
    uut: bounded_hist_bd_wrapper PORT MAP (
          ap_clk => clk,
          ap_ready => open,
          ap_rst => reset,
          ap_start => ap_start_in,
          in1 => in1,
          spike_V => spike_V_out
        );       

     -- Clock process definitions( clock with 50% duty cycle is generated here.
       clk_process :process
       begin
            clk <= '0';
            wait for clk_period/2;  --for 0.5 ns signal is '0'.
            clk <= '1';
            wait for clk_period/2;  --for next 0.5 ns signal is '1'.
       end process;

      -- Reset stimulus process
      res_proc: process
       begin         
            reset <= '1';
            wait for 35 ns;
            reset <= '0';
            wait for 3 ns;
            ap_start_in <= '1';
            wait for 2ms;
      end process;

      -- Input Stimulus process
      in_proc: process
       begin         
            wait for 200 ns;
            in1 <= '1';
            wait for 480 ns;
            in1 <= '0';
            wait for 80 ns;
            in1 <= '1';
            wait for 240 ns;
            in1 <= '0';
            wait for 80 ns;
            in1 <= '1';
            wait for 400 ns;
            in1 <= '0';
            wait for 2ms;
      end process;

end Behavioral;
