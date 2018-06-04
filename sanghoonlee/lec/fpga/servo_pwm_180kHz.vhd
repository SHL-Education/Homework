----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 06/04/2018 10:50:47 AM
-- Design Name: 
-- Module Name: servo_pwm_180kHz - Behavioral
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

entity servo_pwm_180kHz is
    port(
        clk : in std_logic;
        reset : in std_logic;
        pos : in std_logic_vector(9 downto 0);
        servo : out std_logic
    );
end servo_pwm_180kHz;

architecture Behavioral of servo_pwm_180kHz is
    component clk_180kHz
        port(
            clk : in std_logic;
            reset : in std_logic;
            clk_out : out std_logic
        );
    end component;
    
    component servo_pwm
        port(
            clk : in std_logic;
            reset : in std_logic;
            pos : in std_logic_vector(9 downto 0);
            servo : out std_logic
        );
    end component;
    
    signal clk_out : std_logic := '0';
begin
    clk_180kHz_map : clk_180kHz port map(
        clk => clk, reset => reset, clk_out => clk_out
    );
    
    servo_pwm_map : servo_pwm port map(
        clk => clk_out, reset => reset,
        pos => pos, servo => servo
    );

end Behavioral;
