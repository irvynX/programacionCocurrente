library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity contador is
    port (
        clk   : in  std_logic;
        reset : in  std_logic;
        out   : out std_logic_vector(3 downto 0)
    );
end entity contador;

architecture Behavioral of contador is
    signal count : unsigned(3 downto 0) := (others => '0');

begin

    process(clk, reset)
    begin
        if (reset = '1') then
            count <= (others => '0');
        elsif (rising_edge(clk)) then
            if (count = "1001") then
                count <= (others => '0');
            else
                count <= count + 1;
            end if;
        end if;
    end process;

    out <= std_logic_vector(count);

end architecture Behavioral;
