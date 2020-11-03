## Preparation tasks (done before the lab at home)

Use schematic of the [LCD keypad shield](../../Docs/arduino_shield.pdf) and find out the connection of LCD display. What data and control signals are used? What is the meaning of these signals?

&nbsp;
VSS => GND \\
VDD => +5V
VD => Trimr/Potenciometr
RS => PB0[8]
R/W => GND
E => PB1[9]
D0 => not conected
D1 => not conected
D2 => not conected
D3 => not conected
D4 => PD4 [4]
D5 => PD5 [5]
D6 => PD6 [6]
D7 => PD7 [7]
LED+ => +5V
LED- => transitor Q1(colector)


&nbsp;

   | **LCD signal(s)** | **AVR pin(s)** | **Description** |
   | :-: | :-: | :-- |
   | RS | PB0 | Register selection signal. Selection between Instruction register (RS=0) and Data register (RS=1) |
   | R/W | GND | Volba čtení nebo zápisu (v tomhle případě jde o zápis) |
   | E | PB1 | Spouštěcí signál pro synchronizaci se sbernicí |
   | D[3:0] | not conected | Datové signály |
   | D[7:4] | PD4:PD7 | Datové signály |

What is the ASCII table? What are the values for uppercase letters `A` to `Z`, lowercase letters `a` to `z`, and numbers `0` to `9` in this table?
Ascii tabulka je tabulka, kde má každý znak přiřazenou číselnou hodnotu
&nbsp;
A:Z => 65:90 (decimal)
&nbsp;
a:z => 97:122 (decimal)
&nbsp;
0:9 => 48:57 (decimal)
