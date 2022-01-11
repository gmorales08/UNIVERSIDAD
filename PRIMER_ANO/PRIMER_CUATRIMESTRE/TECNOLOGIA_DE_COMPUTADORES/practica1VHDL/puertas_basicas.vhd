library ieee;
use ieee.std_logic_1164.all;

entity not1 is
  port (a: in std_logic;
        z: out std_logic);
end not1;

architecture arq1 of not1 is
begin
  z <= not a;
end arq1;
--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity and2 is
  port(a, b: in std_logic;
           z: out std_logic);
end and2;

architecture arq_1 of and2 is
begin
  z <= a and b;
end arq_1;
--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity and3 is
  port(a, b, c: in std_logic;
           z: out std_logic);
end and3;

architecture arq_1 of and3 is
begin
  z <= a and b and c;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity and4 is
  port(a, b, c, d: in std_logic;
           z: out std_logic);
end and4;

architecture arq_1 of and4 is
begin
  z <= a and b and c and d;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity and5 is
  port(a, b, c, d, e: in std_logic;
           z: out std_logic);
end and5;

architecture arq_1 of and5 is
begin
  z <= a and b and c and d and e;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity and6 is
  port(a, b, c, d, e, f: in std_logic;
           z: out std_logic);
end and6;

architecture arq_1 of and6 is
begin
  z <= a and b and c and d and e and f;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity and7 is
  port(a, b, c, d, e, f, g: in std_logic;
           z: out std_logic);
end and7;

architecture arq_1 of and7 is
begin
  z <= a and b and c and d and e and f and g;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity or2 is
  port(a, b: in std_logic;
           z: out std_logic);
end or2;

architecture arq_1 of or2 is
begin
  z <= a or b;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity or3 is
  port(a, b, c: in std_logic;
           z: out std_logic);
end or3;

architecture arq_1 of or3 is
begin
  z <= a or b or c;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity or4 is
  port(a, b, c, d: in std_logic;
           z: out std_logic);
end or4;

architecture arq_1 of or4 is
begin
  z <= a or b or c or d;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity or5 is
  port(a, b, c, d, e: in std_logic;
           z: out std_logic);
end or5;

architecture arq_1 of or5 is
begin
  z <= a or b or c or d or e;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity or6 is
  port(a, b, c, d, e, f: in std_logic;
           z: out std_logic);
end or6;

architecture arq_1 of or6 is
begin
  z <= a or b or c or d or e or f;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity or7 is
  port(a, b, c, d, e, f, g: in std_logic;
           z: out std_logic);
end or7;

architecture arq_1 of or7 is
begin
  z <= a or b or c or d or e or f or g;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity or8 is
  port(a, b, c, d, e, f, g, h: in std_logic;
           z: out std_logic);
end or8;

architecture arq_1 of or8 is
begin
  z <= a or b or c or d or e or f or g or h;
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nand2 is
  port(a, b: in std_logic;
           z: out std_logic);
end nand2;

architecture arq_1 of nand2 is
begin
  z <= not(a and b);
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nand3 is
  port(a, b, c: in std_logic;
           z: out std_logic);
end nand3;

architecture arq_1 of nand3 is
begin
  z <= not (a and b and c);
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nand4 is
  port(a, b, c, d: in std_logic;
           z: out std_logic);
end nand4;

architecture arq_1 of nand4 is
begin
  z <= not(a and b and c and d);
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nand5 is
  port(a, b, c, d, e: in std_logic;
           z: out std_logic);
end nand5;

architecture arq_1 of nand5 is
begin
  z <= not (a and b and c and d and e);
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nand6 is
  port(a, b, c, d, e, f: in std_logic;
           z: out std_logic);
end nand6;

architecture arq_1 of nand6 is
begin
  z <= not (a and b and c and d and e and f);
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nand7 is
  port(a, b, c, d, e, f, g: in std_logic;
           z: out std_logic);
end nand7;

architecture arq_1 of nand7 is
begin
  z <= not (a and b and c and d and e and f and g);
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nor2 is
  port(a, b: in std_logic;
           z: out std_logic);
end nor2;

architecture arq_1 of nor2 is
begin
  z <= not(a or b);
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nor3 is
  port(a, b, c: in std_logic;
           z: out std_logic);
end nor3;

architecture arq_1 of nor3 is
begin
  z <= not (a or b or c);
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nor4 is
  port(a, b, c, d: in std_logic;
           z: out std_logic);
end nor4;

architecture arq_1 of nor4 is
begin
  z <= not (a or b or c or d);
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nor5 is
  port(a, b, c, d, e: in std_logic;
           z: out std_logic);
end nor5;

architecture arq_1 of nor5 is
begin
  z <= not(a or b or c or d or e);
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nor6 is
  port(a, b, c, d, e, f: in std_logic;
           z: out std_logic);
end nor6;

architecture arq_1 of nor6 is
begin
  z <= not(a or b or c or d or e or f);
end arq_1;

--------------------------------------------

library ieee;
use ieee.std_logic_1164.all;

entity nor7 is
  port(a, b, c, d, e, f, g: in std_logic;
           z: out std_logic);
end nor7;

architecture arq_1 of nor7 is
begin
  z <= not(a or b or c or d or e or f or g);
end arq_1;

