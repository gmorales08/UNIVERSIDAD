library ieee;  
use ieee.std_logic_1164.all;

entity test_multiple is
end test_multiple;

architecture test of test_multiple is
    signal x: std_logic_vector(3 downto 0):="0000";
    signal z2, z1, z0, z21, z11: std_logic_vector(3 downto 0);
begin
  
  sdp: entity work.practica_1(concurrente_sdp) port map (x,z2);
  pds: entity work.practica_1(concurrente_pds) port map (x,z1);
  estructural_nor: entity work.practica_1(estructural_nor) port map (x,z0);
  e_deco: entity work.practica_1(estructural_deco) port map (x,z21);
  e_mux: entity work.practica_1(estructural_mux) port map (x,z11);
 
  x(0) <= not x(0)after 2 ns;
  x(1) <= not x(1)after 4 ns;
  x(2) <= not x(2)after 8 ns;
  x(3) <= not x(3)after 16 ns;
  
end test;  
