library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity servo_pwm is
    port(
        clk : in std_logic;
        reset : in std_logic;
        pos : in std_logic_vector(7 downto 0);
        servo : out std_logic
    );
end servo_pwm;

architecture Behavioral of servo_pwm is
    signal cnt : unsigned(11 downto 0);
    signal pwmi : unsigned(9 downto 0);
begin
    pwmi <= "00" & unsigned(pos) + 180;
    counter : process(reset, clk) begin
        if(reset = '1') then
            cnt <= (others => '0');
        elsif rising_edge(clk) then
            if(cnt = 3599) then
                cnt <= (others => '0');
            else
                cnt <= cnt + 1;
            end if;
        end if;
    end process;
    
    servo <= '1' when (cnt < pwmi) else '0';

end Behavioral;