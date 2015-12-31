----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 08/25/2015 01:27:49 AM
-- Design Name: 
-- Module Name: missile_tb - Behavioral
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

entity missile_tb is
--  Port ( );
end missile_tb;

architecture Behavioral of missile_tb is

    COMPONENT missile_bd_wrapper  --'test' is the name of the module needed to be tested.
    --just copy and paste the input and output ports of your module as such. 
    PORT(
        ap_clk              :   in STD_LOGIC;
        ap_rst              :   in STD_LOGIC;
        ap_start            :   in STD_LOGIC;
        detonation          :   in STD_LOGIC;
        fire_en             :   in STD_LOGIC;      
        launch_en           :   in STD_LOGIC;
        missile_mon         :   out STD_LOGIC_VECTOR(0 to 0)
        );
    END COMPONENT;
       --declare inputs and initialize them
       signal ap_clk_s : std_logic := '0';
       signal ap_rst_s : std_logic := '0';
       signal ap_start_s : std_logic := '0';
       signal detonation_s : std_logic := '0';
       signal fire_en_s : std_logic := '0';
       signal launch_en_s : std_logic := '0';
       signal missile_mon_s : std_logic_vector (0 to 0);            
       --declare outputs and initialize them
       -- Clock period definitions
       constant clk_period : time := 80 ns;
begin
       -- Instantiate the Unit Under Test (UUT)
    uut: missile_bd_wrapper PORT MAP (
            ap_clk          =>  ap_clk_s,
            ap_rst          =>  ap_rst_s, 
            ap_start        =>  ap_start_s,  
            detonation      =>  detonation_s,
            fire_en         =>  fire_en_s,
            launch_en       =>  launch_en_s,
            missile_mon     =>  missile_mon_s
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
            -- nominal case (everything is fine)      
            launch_en_s <= '0';
            fire_en_s <= '0';
            detonation_s <= '0';
            wait for 320 ns;
            launch_en_s <= '1';
            wait for 240 ns;
            fire_en_s <= '1';
            wait for 560 ns;
            detonation_s <= '1';
            wait for 240 ns;
            launch_en_s <= '0';
            fire_en_s <= '0';
            detonation_s <= '0';
            -- fire_en too late case
            wait for 240 ns;
            launch_en_s <= '1';
            wait for 400 ns;
            fire_en_s <= '1';
            wait for 640 ns;
            detonation_s <= '1';
            wait for 240 ns;
            launch_en_s <= '0';
            fire_en_s <= '0';
            detonation_s <= '0';
            -- detonation too early case
            wait for 240 ns;
            launch_en_s <= '1';
            wait for 160 ns;
            fire_en_s <= '1';
            wait for 320 ns;
            detonation_s <= '1';
            wait for 640 ns;
            launch_en_s <= '0';
            fire_en_s <= '0';
            detonation_s <= '0';
            wait for 3ms;
      end process;

end Behavioral;
