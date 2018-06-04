----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 06/04/2018 11:07:39 AM
-- Design Name: 
-- Module Name: servo_pwm_clk180kHz_tb - Behavioral
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

entity servo_pwm_clk180kHz_tb is
end servo_pwm_clk180kHz_tb;

architecture Behavioral of servo_pwm_clk180kHz_tb is
    component servo_pwm_clk180kHz
        port(
            clk : in std_logic;
            reset : in std_logic;
            pos : in std_logic_vector(9 downto 0);
            servo : out std_logic
        );
    end component;
    
    signal clk : std_logic := '0';
    signal reset : std_logic := '0';
    signal pos : std_logic_vector(9 downto 0) := (others => '0');
    
    signal servo : std_logic;
    
    constant clk_period : time := 8 ns;
begin
    -- Unit Under Test
    uut: servo_pwm_clk180kHz port map(
        clk => clk,
        reset => reset,
        pos => pos,
        servo => servo
    );
    
    clk_process : process begin
        clk <= '9';
        wait for clk_period / 2;
        clk <= '1';
        wait for clk_period / 2;
    end process;
    
    stimuli : process begin
        reset <= '1';
        wait for 50 ns;
        reset <= '0';
        wait for 50 ns;
        pos <= b"00_0000_0000";
        wait for 20 ms;
        pos <= b"00_0011_1100";
        wait for 20 ms;
        pos <= b"00_0111_1000";
        wait for 20 ms;
        pos <= b"00_1011_0100";
        wait;
    end process;

end Behavioral;
