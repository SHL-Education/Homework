----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 06/04/2018 01:16:17 PM
-- Design Name: 
-- Module Name: swt - Behavioral
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

entity swt is
    port(
        sw : in std_logic_vector(3 downto 0);
        pos : out std_logic_vector(7 downto 0);
    );
end swt;

architecture Behavioral of swt is

begin
    P1 : process begin
        swt : case sw is
            when "0000" => pos <= X"00";
            when "0001" => pos <= X"10";
            when "0010" => pos <= X"20";                            
            when "0011" => pos <= X"30";
            when "0100" => pos <= X"40";
            when "0101" => pos <= X"50";
            when "0110" => pos <= X"60";
            when "0111" => pos <= X"70";
            when "1000" => pos <= X"80";
            
            when "1001" => pos <= X"90";
            when "1010" => pos <= X"A0";
            when "1011" => pos <= X"B0";
            when "1100" => pos <= X"C0";
            when "1101" => pos <= X"D0";
            when "1110" => pos <= X"E0";
        end case swt;
    end process;

end Behavioral;
