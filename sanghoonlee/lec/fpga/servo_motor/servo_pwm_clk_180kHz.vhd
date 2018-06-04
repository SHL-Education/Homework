library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity servo_pwm_clk_180kHz is
    port(
        clk : in std_logic;
        reset : in std_logic;
        sw : in std_logic_vector(3 downto 0);
        servo : out std_logic
    );
end servo_pwm_clk_180kHz;

architecture Behavioral of servo_pwm_clk_180kHz is
    component switch
        port(
            sw : in std_logic_vector(3 downto 0);
            pos : out std_logic_vector(7 downto 0)
        );
    end component;

    component clk_180kHz
        port(
            clk_in : in std_logic;
            reset : in std_logic;
            clk_out : out std_logic
        );
    end component;
    
    component servo_pwm
        port(
            clk : in std_logic;
            reset : in std_logic;
            pos : in std_logic_vector(7 downto 0);
            servo : out std_logic
        );
    end component;
    
    signal clk_out : std_logic := '0';
    signal pos : std_logic_vector(7 downto 0);
begin
    switch_in : switch port map(
        sw => sw, pos => pos
    );

    clk_180kHz_map : clk_180kHz port map(
        clk_in => clk, reset => reset, clk_out => clk_out
    );
    
    servo_pwm_map : servo_pwm port map(
        clk => clk_out, reset => reset,
        pos => pos, servo => servo
    );

end Behavioral;