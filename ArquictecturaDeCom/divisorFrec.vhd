library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity clk200Hz is
    Port ( ent50 : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           sal200 : out  STD_LOGIC);
end clk200Hz;

architecture Behavioral of clk200Hz is
    signal temporal: STD_LOGIC;
    signal contador: integer range 0 to 124999 := 0;

 

begin
    process (ent50, rst) 
    begin
        if (rst = '1') then
            temporal <= '0';
            contador <= 0;
        elsif rising_edge(ent50) then
            if contador = 124999 then
                temporal <= not temporal;
                contador <= 0;
            else
                contador <= contador + 1;
            end if;
        end if;    
    end process;
sal200 <= temporal;
end Behavioral;