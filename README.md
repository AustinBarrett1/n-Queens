# n-Queens
A C++ project that solves the classic n-Queens problem without using recursion.

This was a project that was assigned in my second year object oriented programming in c++. I worked with shade-kaiser on developing a solution. Provided is a simple cpp file. 

The following is the question that was presented.

-  A function to get the user input value for N
  -  N is an unsigned short integer, strictly greater than 0 and less than 14
  -  Validate the input, including for if the user enteres non-numeric values; reprompt until a valid value is entered
-  A function which checks to see if the current placement of queens is valid (i.e. no two queens can attack each other)
-  A function which places the queens in the NxN board (a 2D array), and determines if the placement is valid
  -  This is function relies on the second function to validate whether the current set up is valid
  -  This function returns the total number of solutions for the value of N
  -  When a solution is found, the positions of the queens should be printed to console (use standard chess notation where rows are numbered from 1 to N, and columns are lettered starting with A
