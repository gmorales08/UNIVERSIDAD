library ieee;
use ieee.std_logic_1164.all;

entity mux8a1 is
  port (enable: in std_logic;
        x: in std_logic_vector(7 downto 0);
        sel: in std_logic_vector(2 downto 0);
        y: out std_logic);
end mux8a1;

architecture funcional of mux8a1 is
begin
  process(enable, x, sel)
    begin
      if enable = '0' then
        y <= '0';
      else
        case sel is
          when "000" => y <= x(0);
          when "001" => y <= x(1);
          when "010" => y <= x(2);
		  when "011" => y <= x(3);
		  when "100" => y <= x(4);
		  when "101" => y <= x(5);
		  when "110" => y <= x(6);		  
          when others => y <= x(7);
        end case;
      end if;        
    end process;
end funcional;
-------------------------------------------------------------------------
library ieee;
use ieee.std_logic_1164.all;

entity deco3a8 is
  port(enable: in std_logic;
        x: in std_logic_vector(2 downto 0);
        y: out std_logic_vector(7 downto 0));
end deco3a8;

architecture funcional of deco3a8 is
begin
	process(enable, x)
	begin
	if enable = '0' then
		y <= (others => '0');
	else
		case x is
		  when "000" => y <= "00000001";
          when "001" => y <= "00000010";
          when "010" => y <= "00000100";
		  when "011" => y <= "00001000";
		  when "100" => y <= "00010000";
		  when "101" => y <= "00100000";
		  when "110" => y <= "01000000";		  
          when others => y <= "10000000";
		end case;
	end if;
	end process;
end funcional;

