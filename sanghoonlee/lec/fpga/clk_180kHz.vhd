----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 06/04/2018 10:29:26 AM
-- Design Name: 
-- Module Name: clk_180kHz - Behavioral
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

entity clk_180kHz is
    port(
        clk_in : in std_logic;
        reset : in std_logic;
        clk_out : out std_logic
    );
end clk_180kHz;

architecture Behavioral of clk_180kHz is
    signal temp : std_logic;
    signal counter : integer range 0 to 346 := 0;
begin
    frequency_divider : process(reset, clk_in)
    begin
        if(reset = '1') then
            temp <= '0';
            counter <= 0;
        elsif rising_edge(clk_in) then
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
