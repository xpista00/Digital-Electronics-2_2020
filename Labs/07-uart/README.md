## Preparation tasks (done before the lab at home)

Use schematic of the [LCD keypad shield](../../Docs/arduino_shield.pdf) and find out the connection of five push buttons: Select, Left, Up, Down, and Right.

&nbsp;

buttons RIGHT, UP, DOWN, LEFT, SELECT  => PC0
button RESET => RESET

According to the connection, calculate the voltage value on pin PC0[A0] if one button is pressed at a time. In this case, the voltage on the pin is given by the [voltage divider](https://www.allaboutcircuits.com/tools/voltage-divider-calculator/), where resistors R3, R4, R5 and R6 are applied successively.

![Equation: Voltage divider](Images/eq_divider1.png)
V(PC-RIGHT)=5*[0/(R2+0)]=5*[0/(3000+0)]=0V

![Equation: Voltage divider](Images/eq_divider2.png)
V(PC-UP)=5*[R3/(R2+R3)]=5*[330/(3000+330)]=0,495V
&nbsp;

![Equation: Voltage divider](Images/eq_divider3.png)
V(PC-DOWN)=5*[R3+R4/(R2+R3+R4)]=5*[330+620/(3000+330+620)]=1,203V
&nbsp;

![Equation: Voltage divider](Images/eq_divider4.png)
V(PC-LEFT)=5*[R3+R4+R5/(R2+R3+R4+R5)]=5*[330+620+1000/(3000+330+620+1000)]=1,970V
&nbsp;

![Equation: Voltage divider](Images/eq_divider5.png)
V(PC-SELECT)=5*[R3+R4+R5+R6/(R2+R3+R4+R5+R6)]=5*[330+620+1000+3300/(3000+330+620+1000+3300)]=3,182V
&nbsp;

What is the voltage value if none of the push buttons is pressed?
=> inf
![Equation: Voltage divider](Images/eq_divider6.png)

&nbsp;

Calculate the ADC values for these voltages according to the following equation if reference is Vref=5V and number of bits for analog to digital conversion is n=10.

![Equation: ADC conversion](Images/eq_adc.png)
ADC=V(PC)*(2^n-1)/ V(ref)=0,495*(2^10-1)/5=

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** |
   | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   |  |
   | Up     | 0.495&nbsp;V | 101 |  |
   | Down   |    1.203   |  246   |  |
   | Left   |   1.970    |   403  |  |
   | Select |    3.182   |   651  |  |
   | none   |     inf  |   inf  |  |
