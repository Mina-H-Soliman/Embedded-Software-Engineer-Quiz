# Embedded-Software-Engineer-Quiz

In this file I will incluide some comments for the code developed

The C file contains code developed for both tasks of the quiz + some test cases + a simple text terminal (CMD) UI to test the code for both tasks 

For the first Task in the quiz I worte the code for the function called Task1LargestSquaresInRectangle 
which is a recursive function that takes both sides of a rectangle M and N 
and then produce the output as specified by printing it on the terminal.

For Task 2 I noticed from the pattern of the generated codes in the spreadsheet 
that the codes could be generated by just transforming the numbers from base10 to base62 using 0-9 A-Z a-z charcters
However from the codes it was appearnt that the order in which the charcters are used is not uniform or apparent
so I developed a function to load all the numbers from a textfile called ResourceNumbers and all the codes from 
the file ResourceCodes then I wrote a function to try to reverse engineer the Cipher used (unique pattern of charcters)
by using the Numbers and Codes given, I also checked if there were any inconsistencies between the codes and there was none
The deduced Cipher is C7xicPMGvzAZyTNodmwnVLD3B6H0Oup8E21W9sqLQX4YjSeUhIRJgafFtrKlbk
instead of the convention :  0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
However there was one charcter which could not be determined form the supplied codes which is at position 21 "L" but it was obvious
that this should be substituted by 5 in order to prevent any collisions or inconsistencies as the 5 was not used and L was used twice
I then wrote another function to use the deduced cipher to generete the corresponding code from any number
The new Cipher is: C7xicPMGvzAZyTNodmwnV5D3B6H0Oup8E21W9sqLQX4YjSeUhIRJgafFtrKlbk

For the function to be as usefull as possible , I made it so that it can work for any number that is in the int range 
incluiding negative numbers assuming a negative numbers are converted just as a positive number with the addition of
a negative sign

I tested the function for some of the given numbers to validate it and solved it for the required numbers in the Quiz document
f(30001) = GIF
f(55555) = NOi
f(77788) = VNQ
Last I made a simple text based UI to test both functions,  however it was not tested and debugged thouroughly as it is just a means 
to test the functions easily without having to re-compile the C file

the example.exe was compliled for X64 windows 10  
both textfiles ResourceNumbers and ResourceCodes should be in the same directory as the .exe or the c file when compiling it 
