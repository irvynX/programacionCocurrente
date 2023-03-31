library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity decoder is
    port (
        input  : in  std_logic_vector(3 downto 0);
        output : out std_logic_vector(6 downto 0)
    );
end entity decoder;

architecture Behavioral of decoder is

begin

    process(input)
    begin
        case input is
            when "0000" => output <= "0000001";
            when "0001" => output <= "1001111";
            when "0010" => output <= "0010010";
            when "0011" => output <= "0000110";
            when "0100" => output <= "1001100";
            when "0101" => output <= "0100100";
            when "0110" => output <= "0100000";
            when "0111" => output <= "0001111";
            when "1000" => output <= "0000000";
            when "1001" => output <= "0000100";
            when others => output <= "1111111";
        end case;
    end process;

end architecture Behavioral;
