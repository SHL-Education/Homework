library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity clk_180kHz is
    port(
        clk : in std_logic;
        reset : in std_logic;
        clk_out : out std_logic
    );
end clk_180kHz;

architecture Behavioral of clk_180kHz is
    signal temp : std_logic;
    signal counter : integer range 0 to 346 := 0;
begin
    frequency_divider : process(reset, clk)
    begin
        if(reset = '1') then
            temp <= '0';
            counter <= 0;
        elsif rising_edge(clk) then
            if(counter = 346) then
                temp <= NOT(temp);
                counter <= 0;
            else
                counter <= counter + 1;
            end if;
        end if;
    end process;
    
    clk_out <= temp;

end Behavioral;