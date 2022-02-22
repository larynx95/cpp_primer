/******************************************************************************
C++ Primer, Stanley B. Lippmann, 2013
Chapter 01. Getting Started

Section 1.1 Writing a Simple C++ Program
Section 1.2 A First Look at Input/Output
Section 1.3 A Word about Comments
Section 1.4 Flow of Control
******************************************************************************/

#include <iostream>

int main() {
  /*
  1.4. Flow of Control

  1.4.1. The while Statement
  (Execises 1.9 ~ 1.11)
  */

  int sum = 0, val = 1;
  // keep executing the while as long as val is less than or equal to 10
  while (val <= 10) {
    sum += val;  // assigns sum + val to sum
    ++val;       // add 1 to val
  }
  std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

  /*
  1.4.2. The for Statement
  (Exercises 1.12 ~ 1.15)
  */

  sum = 0;
  // sum values from 1 through 10 inclusive
  for (int val = 1; val <= 10; ++val)
    sum += val;  // equivalent to sum = sum + val
  std::cout << "Sum of 1 to 10 inclusive is " << sum << std::endl;

  /*
  1.4.3. Reading an Unknown Number of Inputs
  (Exercise 1.16)

  TODO: Entering an ENd-of-File from the Keyboard
  "Ctrl-z" in Windows system
  "Ctrl-d" in Unix, OS X
  */

  sum = 0;
  int value = 0;
  // read until end-of-file, calculating a running total of all values read
  while (std::cin >> value)  // using istream as a condition
    sum += value;            // equivalent to sum = sum + value
  std::cout << "Sum is: " << sum << std::endl;

  /*
  1.4.4. The if Statement
  (Exercises 1.17 ~ 1.19)
  */

  // currVal is the number we're counting; we'll read new values into val     
  int currVal = 0, val = 0;
  // read first number and ensure that we have data to process     
  if (std::cin >> currVal) {
    // store the count for the current value we're processing   
    int cnt = 1;
    while (std::cin >> val) {  // read the remaining numbers
      if (val == currVal)      // if the values are the same    
        ++cnt;                 // add 1 to cnt      
      else {  // otherwise, print the count for the previous value            
        std::cout << currVal << " occurs " << cnt << " times" << std::endl;
        currVal = val;  // remember the new value
        cnt = 1;        // reset the counter
      }
    }  // while loop ends here   
    // remember to print the count for the last value in the file         
    std::cout << currVal << " occurs " << cnt << " times" << std::endl;
  }  // outermost if statement ends here

  return 0;
}

/*
Section 1.5 Introducing Classes
Section 1.6 The Bookstore Program
*/