----------------------------------------------------
----- GABRIEL MORALES DATO y UNAI RETES CORADA -----
----- ING. INFORMATICA E ING. DE COMPUTADORES  -----
----- TECNOLOGIA DE COMPUTADORES - PRACTICA 2  -----
----------------------------------------------------

-------------------------------------------------------------------------------------------------------------
----- Se desea diseñar un circuito secuencial que tiene una entrada de datos x de 1 bit, una entrada    -----
----- de reset y una entrada de reloj. El sistema es capaz de realizar la función que aparece reflejada -----
----- en la siguiente tabla de verdad:                                                                  -----
-------------------------------------------------------------------------------------------------------------

--+-----+-----+-----+   +-----+-----+-----+
--|  Q1 |  Q0 |  X  |   | Q'1 | Q'0 |  Z  |  
--+-----+-----+-----+   +-----+-----+-----+
--|  0  |  0  |  0  |   |  0  |  0  |  0  |
--+-----+-----+-----+   +-----+-----+-----+
--|  0  |  0  |  1  |   |  0  |  1  |  0  |
--+-----+-----+-----+   +-----+-----+-----+
--|  0  |  1  |  0  |   |  1  |  0  |  0  |
--+-----+-----+-----+   +-----+-----+-----+
--|  0  |  1  |  1  |   |  0  |  1  |  0  |
--+-----+-----+-----+   +-----+-----+-----+
--|  1  |  0  |  0  |   |  0  |  1  |  0  |
--+-----+-----+-----+   +-----+-----+-----+
--|  1  |  0  |  1  |   |  1  |  1  |  0  |
--+-----+-----+-----+   +-----+-----+-----+
--|  1  |  1  |  0  |   |  1  |  0  |  0  |
--+-----+-----+-----+   +-----+-----+-----+
--|  1  |  1  |  1  |   |  0  |  1  |  1  |
--+-----+-----+-----+   +-----+-----+-----+


----- LIBRERIAS -----
library ieee;
use ieee.std_logic_1164.all;
---------------------


----- ENTIDADES -----
entity practica_2 is
    port (clk, rst, x: in  std_logic;
          z          : out std_logic);
end entity practica_2;
---------------------


----- ARQUITECTURAS -----

    --b) Implementar el sistema utilizando flip-flops tipo D además de puertas lógicas auxiliares. Describir el circuito obtenido en VHDL utilizando los flip-flops D proporcionados en el archivo “flip-flops.vhd”, y puertas lógicas o expresiones concurrentes auxiliares. El nombre de esta arquitectura debe ser estructural_D.

architecture estructural_D of practica_2 is 

    signal Q0, Q0_NS, Q1, Q1_NS : std_logic; -- Q0 y Q1 corresponden al estado actual 1 y 2, 
                                             -- Q0_NS Y Q1_NS corresponden a los siguientes estados

begin

    Q0_NS <= (Q1 and not Q0) or x;
    Q1_NS <= (Q1 and not Q0 and x) or (Q0 and not x);
    z     <= Q1 and Q0 and x;

    flipFlopD1: entity work.flipflopD port map (clk, rst, Q0_NS, Q0);
    flipFlopD2: entity work.flipflopD port map (clk, rst, Q1_NS, Q1);

    --Observaciones: primero hemos codificado la tabla de verdad a partir de la tabla de transición de estados. Con la tabla de verdad hemos obtenido las expresiones simplificadas de Q0_NS y Q1_NS, que representan el siguiente estado, y de la salida, z. Los valores de Q0_NS y Q1_NS los hemos asignado a la entrada de los flip flop tipo D, y los valores de Q0 y Q1 los hemos asignado a las salidas de estos flip flop.

end architecture estructural_D;


    --c) Implementar el sistema utilizando flip-flops tipo JK además de puertas lógicas auxiliares. Describir el circuito obtenido en VHDL utilizando los flip-flops JK proporcionados en el archivo “flip-flops.vhd”, y puertas lógicas o expresiones concurrentes auxiliares. El nombre de esta arquitectura debe ser estructural_JK

architecture estructural_JK of practica_2 is

    signal Q0, J0, K0, Q1, J1, K1: std_logic; -- Q son las salidas del flip flop y JK son las entradas

begin 

    J0 <= Q1 or x;
    K0 <= not x;
    J1 <= Q0 and not x;
    K1 <= (not Q0 and not x) or (Q0 and x);
    z  <= Q1 and Q0 and x;

    flipFlopJK1: entity work.flipFlopJK port map (clk, rst, J0, K0, Q0);
    flipFlopJK2: entity work.flipFlopJK port map (clk, rst, J1, K1, Q1);

end architecture estructural_JK;

    --Observaciones: con la tabla de verdad del apartado anterior y observando la tabla de excitación de los flip flop JK, hemos obtenido una tabla equivalente usando dos flip flop JK. De esta tabla hemos obtenido las expresiones simplificadas de las entradas de los flip flop (J0, K0, J1 y K1) y la salida, z.


    -- d) Describir en VHDL el sistema mediante una descripción funcional con dos procesos, uno para la parte combinacional y otro para la parte secuencial. El nombre de esta arquitectura debe ser fsm_funcional

architecture fsm_funcional of practica_2 is
    
    type estados is (S0, S1, S2, S3); --Creamos un tipo de datos para identificar los estados
    signal ns, ps: estados; --ns: next state, ps: present state

begin
   --Proceso para la parte combinacional
    process(x, ps)
    begin 
        case ps is
            when S0 => if x = '0' then ns <= S0; z <= '0';
                       else            ns <= S1; z <= '0';
                       end if;
            when S1 => if x = '0' then ns <= S2; z <= '0';
                       else            ns <= S1; z <= '0';
                       end if;
            when S2 => if x = '0' then ns <= S1; z <= '0';
                       else            ns <= S3; z <= '0';
                       end if;
            when S3 => if x = '0' then ns <= S2; z <= '0';
                       else            ns <= S1; z <= '1';
                       end if;
        end case;
    end process;

    --Proceso para la parte secuencial
    process(clk, rst)
    begin
        if rst = '1' then ps <= S0;
        elsif rising_edge(clk) then ps <= ns;
        end if;
    end process;

end architecture fsm_funcional;

--Observaciones: para describir la fsm en VHDL hemos creado un tipo de datos "estados" que utilizaran las señales de estado actual y estado siguiente. Hemos usado dos procesos, uno para la parte combinacional, que gestiona el cambio entre estados y se ejecuta cuando cambian las señales x (entrada) y ps(estado actual). El otro proceso, para la parte secuencial, se encarga de cambiar los estados cuando cambia el pulso de reloj o cuando se habilita la señal reset. Este se activa cuando cambian las señales clk o rst.
-------------------------
