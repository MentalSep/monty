+++++ ++++           add 9 to Cell #0 and use it as index for the next loop
>,>,<<               take input and store the first digit in Cell #1 and second digit in Cell #2
[>----- >----- <<-]  decrement both Cell #1 and Cell #2 by 5 until Cell #0 is 0
>--->---             decrement both Cell #1 and Cell #2 by 3 to get the int value of the input
[<+>-]               increment Cell #1 by 1 and decrement Cell #2 by 1 to get the sum of the digits
+++++ ++++           add 9 to Cell #2 and use it as index for next loop
[<+++++ >-]          add 5 to Cell #1 until Cell #2 is 0
<+++.                add 3 to Cell #1 to get the ASCII value of the summed digits and print it
