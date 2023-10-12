# View WRITEUP.pdf to view created estimations

How to run and use mathlib-test.c
================================


What does it do?
----------------
> Tests mathlib.c which is a small math library containing approximation functions for:
> Sin, Cos, Arcsin, Arccos, Arctan, log(x).
>
> The values are then compared to the C math library and the error between values is also included.


Command Line Options
--------------------
> Every test outputs a table of values in the input range from my_function and the C math
> library function. It also computes the error between the two values.
>

> '-a' This option will run all available tests (Sin, Cos, Arcsin, Arccos, Arctan, log)
> within their respective testing values
>
> '-s' Tests the sin function between the input values of (0,2pi) with steps of 0.05pi.

> '-c' Tests the cos function between the input values of (0,2pi) with steps of 0.05pi.

> '-S' Tests the arcsin function between the input values of [-1,1) with steps of 0.05.

> '-C' Tests the arccos function between the input values of [-1,1) with steps of 0.05.

> '-T' Tests the arctan function between the input values of [1,10) with steps of 0.05.

> '-l' Tests the log function between the input values of [1,10) with steps of 0.05.


How to build and run the program.
=================================

Step One:
---------
> Ensure that the files:

> "Makefile"
> "mathlib.c"
> "mathlib.h"
> "mathlib-test.c"
>
> Are all inside the same directory.
>
Step Two:
---------
> Open the terminal in the directory and type "make"
>
Step Three:
-----------
> Run the tests you would like by typing "./mathlib-test -#"

> Replace the "#" with the corresponding character from the above "Command Line Options section.

> You can include multiple tests in a single run through of the function! (EX: "./mathlib-test -s -S -c -C" or "./mathlib-test -T -C -s -S -c -l -a")

Understanding the table:
------------------------
> The first column is the input value "x" that was given to both functions.

> The second column is my approximation implementation of the function.

> The third column is the value returned by the same function from the C math library.

> The last column is the error |my_value - library_value| which shows the difference between the two values.



