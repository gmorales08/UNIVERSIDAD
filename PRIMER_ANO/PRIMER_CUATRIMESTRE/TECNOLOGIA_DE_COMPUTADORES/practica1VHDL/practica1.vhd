----------------------------------------------------
----- GABRIEL MORALES DATO y UNAI RETES CORADA -----
----- ING. INFORMATICA E ING. DE COMPUTADORES  -----
----- TECNOLOGIA DE COMPUTADORES - PRACTICA 1  -----
----------------------------------------------------

-----------------------------------------------------------------------
----- DISENAR UN CIRCUITO COMBINACIONAL CON UNA ENTRADA DE 4 BITS -----
----- Y UNA SALIDA DE 4 BITS CUYO VALOR CONSISTA EN EL RESULTADO  -----
----- DE REDONDEAR LA OPERACION (3*√y) AL ENTERO MAS PROXIMO      -----
-----------------------------------------------------------------------

-----------------------------------------------------------------------
----- TABLA DE VALORES DE LA FUNCION                              -----
-----------------------------------------------------------------------

--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  y3 |  y2 |  y1 |  y0 |     |  z3 |  z2 |  z1 |  z0 |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  0  |  0  |  0  |  0  | --> |  0  |  0  |  0  |  0  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  0  |  0  |  0  |  1  | --> |  0  |  0  |  1  |  1  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  0  |  0  |  1  |  0  | --> |  0  |  1  |  0  |  0  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  0  |  0  |  1  |  1  | --> |  0  |  1  |  0  |  1  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  0  |  1  |  0  |  0  | --> |  0  |  1  |  1  |  0  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  0  |  1  |  0  |  1  | --> |  0  |  1  |  1  |  1  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  0  |  1  |  1  |  0  | --> |  0  |  1  |  1  |  1  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  0  |  1  |  1  |  1  | --> |  1  |  0  |  0  |  0  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  1  |  0  |  0  |  0  | --> |  1  |  0  |  0  |  0  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  1  |  0  |  0  |  1  | --> |  1  |  0  |  0  |  1  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  1  |  0  |  1  |  0  | --> |  1  |  0  |  0  |  1  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  1  |  0  |  1  |  1  | --> |  1  |  0  |  1  |  0  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  1  |  1  |  0  |  0  | --> |  1  |  0  |  1  |  0  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  1  |  1  |  0  |  1  | --> |  1  |  0  |  1  |  1  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  1  |  1  |  1  |  0  | --> |  1  |  0  |  1  |  1  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+
--|  1  |  1  |  1  |  1  | --> |  1  |  1  |  0  |  0  |
--+-----+-----+-----+-----+-----+-----+-----+-----+-----+



----- LIBRERIAS -----
library ieee;
use ieee.std_logic_1164.all;
---------------------


----- ENTIDADES -----
entity practica_1 is
    port (y : in  std_logic_vector(3 downto 0);
          z : out std_logic_vector(3 downto 0));
end entity practica_1;
---------------------


----- ARQUITECTURAS -----

   -- a) Obtener la expresion mas simplificada de z2 en forma de SOP utilizando una asignacion concurrente

architecture concurrente_sdp of practica_1 is 
begin 

    z(2) <= (not y(3) and not y(2) and y(1)) or
            (not y(3) and y(2) and not y(1)) or
            (y(3) and y(2) and y(1) and y(0)) or
            (not y(3) and y(1) and not y(0));

end architecture concurrente_sdp;

   --Observaciones: para obtener esta expresion hemos utilizado los mapas de kargnauth y hemos obtenido la expresion simplificada de la funcion 

-------------------------

   -- b) Obtener la expresion mas simplificada de z1 en forma de POS utilizando una asignacion concurrente

architecture concurrente_pds of practica_1 is
begin

    z(1) <= (y(2) or y(0)) and
            (not y(3) or y(2) or y(1)) and
            (not y(2) or not y(1) or not y(0)) and
            (y(3) or not y(1) or not y(0));

end architecture concurrente_pds;

   --Observaciones: para obtener esta expresion hemos utilizado los mapas de kargnauth y hemos obtenido la expresion simplificada de la funcion 

-------------------------

   -- c) Implementar z0 utilizando solo puertas NOR (y opcionalmente inversores)
architecture estructural_nor of practica_1 is 

    -- senales

    signal noY0, noY1, noY2, noY3: std_logic;
    signal salidaNorA, salidaNorB, salidaNorC, salidaNorD: std_logic;

begin
    no_y0: entity work.not1 port map (y(0), noY0);
    no_y1: entity work.not1 port map (y(1), noY1);
    no_y2: entity work.not1 port map (y(2), noY2);
    no_y3: entity work.not1 port map (y(3), noY3);
    norA:  entity work.nor3 port map (y(3), y(2), y(0), salidaNorA);
    norB:  entity work.nor2 port map (y(1), y(0), salidaNorB);
    norC:  entity work.nor3 port map (noY2, noY1, noY0, salidaNorC);
    norD:  entity work.nor3 port map (noY3, noY1, noY0, salidaNorD);
    norE:  entity work.nor4 port map (salidaNorA, salidaNorB, salidaNorC, salidaNorD, z(0));

end architecture estructural_nor;

   --Observaciones: Para hacer este apartado, primero hemos simplificado la funcion obtenida a partir del mapa de kargnauth. Luego hemos creado un circuito a partir de la funcion, y este circuito lo hemos transformado en uno equivalente usando solo puertas NOR e inversores.

-------------------------

   -- d) Implementar z2 utilizando un decodificador 3 a 8 y puertas logicas auxiliares
architecture estructural_deco of practica_1 is

   -- A continuacion vamos a describir las senales que utilizaremos en el decodificador
   signal no_y3, salida_or, salida_and2_1, salida_and2_2: std_logic;
   signal deco_entradas:                                  std_logic_vector(2 downto 0);
   signal deco_salidas:                                   std_logic_vector(7 downto 0);

begin
    -- asignamos valores a las entradas y salidas de deco3a8
    deco_entradas(0) <= y(0);
    deco_entradas(1) <= y(1);
    deco_entradas(2) <= y(2);
    -- definimos los componentes
    deco3a8: entity work.deco3a8 port map ('1', deco_entradas, deco_salidas); 
    inv3:    entity work.not1    port map (y(3), no_y3);
    or5:     entity work.or5     port map (deco_salidas(2), deco_salidas(3), deco_salidas(4), deco_salidas(5), deco_salidas(6), salida_or);
    and2_1:  entity work.and2    port map (no_y3, salida_or, salida_and2_1);
    and2_2:  entity work.and2    port map (deco_salidas(7), y(3), salida_and2_2);
    or2:     entity work.or2     port map (salida_and2_1, salida_and2_2, z(2));

end architecture estructural_deco;

    --Observaciones: Primero hicimos el circuito con dos decodificadores y despues los combinamos en uno, sacando las salidas del primer decodificador en un or, y las salidas del segundo decodificador a otro or, luego simplificando el circuito pudimos hacerlo usando un solo decodificador y un solo or. 
-------------------------

    -- e) Implementar z1 utlizando un multiplexor de 8 a 1 y puertas logicas auxiliares

    -- Para poder hacer uso de un decodificador con tres canales de seleccion, teniendo que implementar una funcion de 4 variables, hemos simplificado la tabla de verdad de z1 en funcion del valor de y0.
    -- La nueva tabla de verdad tiene 8 valores que se corresponden con las 8 entradas del multiplexor, de esta manera podemos usar y0 como una entrada mas, y dejar y1, y2 e y3 para los canales de seleccion del multiplexor.

--+-----+-----+-----+-----+-----+-----+       +-----+
--|  y3 |  y2 |  y1 |  y0 |     |  z1 |       |  g  |
--+-----+-----+-----+-----+-----+-----+       +-----+
--|  0  |  0  |  0  |  0  | --> |  0  |       |     |
--+-----+-----+-----+-----+-----+-----+       |  y0 |
--|  0  |  0  |  0  |  1  | --> |  1  |       |     |
--+-----+-----+-----+-----+-----+-----+       +-----+
--|  0  |  0  |  1  |  0  | --> |  0  |       |     |
--+-----+-----+-----+-----+-----+-----+       |  0  |
--|  0  |  0  |  1  |  1  | --> |  0  |       |     |
--+-----+-----+-----+-----+-----+-----+       +-----+
--|  0  |  1  |  0  |  0  | --> |  1  |       |     |
--+-----+-----+-----+-----+-----+-----+       |  1  |
--|  0  |  1  |  0  |  1  | --> |  1  |       |     |
--+-----+-----+-----+-----+-----+-----+       +-----+
--|  0  |  1  |  1  |  0  | --> |  1  |       |  __ |
--+-----+-----+-----+-----+-----+-----+       |  y0 |
--|  0  |  1  |  1  |  1  | --> |  0  |       |     |
--+-----+-----+-----+-----+-----+-----+  ==>  +-----+
--|  1  |  0  |  0  |  0  | --> |  0  |       |     |
--+-----+-----+-----+-----+-----+-----+       |  0  |
--|  1  |  0  |  0  |  1  | --> |  0  |       |     |
--+-----+-----+-----+-----+-----+-----+       +-----+
--|  1  |  0  |  1  |  0  | --> |  0  |       |     |
--+-----+-----+-----+-----+-----+-----+       |  y0 |
--|  1  |  0  |  1  |  1  | --> |  1  |       |     |
--+-----+-----+-----+-----+-----+-----+       +-----+
--|  1  |  1  |  0  |  0  | --> |  1  |       |     |
--+-----+-----+-----+-----+-----+-----+       |  1  |
--|  1  |  1  |  0  |  1  | --> |  1  |       |     |
--+-----+-----+-----+-----+-----+-----+       +-----+
--|  1  |  1  |  1  |  0  | --> |  1  |       |  __ |
--+-----+-----+-----+-----+-----+-----+       |  y0 |
--|  1  |  1  |  1  |  1  | --> |  0  |       |     |
--+-----+-----+-----+-----+-----+-----+       +-----+

architecture estructural_mux of practica_1 is

    signal entradas_mux   : std_logic_vector(7 downto 0);
    signal selectores_mux : std_logic_vector(2 downto 0);
    signal no_y0          : std_logic;

begin

    mux8a1: entity work.mux8a1 port map('1', entradas_mux, selectores_mux, z(1));
    inv_y0 : entity work.not1   port map(y(0), no_y0);    

    --asignamos las entradas
    entradas_mux(0) <= y(0);
    entradas_mux(1) <= '0';
    entradas_mux(2) <= '1';
    entradas_mux(3) <= no_y0;
    entradas_mux(4) <= '0';
    entradas_mux(5) <= y(0);
    entradas_mux(6) <= '1';
    entradas_mux(7) <= no_y0;

    --asignamos los selectores
    selectores_mux(0) <= y(1);
    selectores_mux(1) <= y(2);
    selectores_mux(2) <= y(3);

end architecture estructural_mux;
-------------------------


----------------------------
