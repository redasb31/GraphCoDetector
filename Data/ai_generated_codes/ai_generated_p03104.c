/*
  Score : 400 points

  Problem Statement
  Let f(A, B) be the exclusive OR of A, A+1, ..., B. Find f(A, B).

  What is exclusive OR?
  The bitwise exclusive OR of integers c_1, c_2, ..., c_n (let us call it y) is defined as follows:

  When y is written in base two, the digit in the 2^k's place (k ≥0) is 1 if, the number of integers among c_1, c_2, ...c_m whose binary representations have 1 in the 2^k's place, is odd, and 0 if that count is even.

  For example, the exclusive OR of 3 and 5 is 6. (When written in base two: the exclusive OR of 011 and 101 is 110.)
*/

#include <stdio.h>

int main() {
  int A, B;
  scanf("%d %d", &A, &B);

  // The XOR of a number with itself is 0. 
  // Therefore, we can pair up the numbers in the range [A, B] and XOR them in pairs.
  // This leaves us with the XOR of the remaining numbers.
  int xor = 0;
  if (A % 2 == 0 && B % 2 == 0) {
    // If A and B are both even, then we have an even number of numbers in the range [A, B].
    // So, we can pair them up and XOR them, leaving us with 0.
    xor = 0;
  } else if (A % 2 == 1 && B % 2 == 1) {
    // If A and B are both odd, then we have an odd number of numbers in the range [A, B].
    // So, we can pair them up and XOR them, leaving us with the XOR of the last number in the range.
    xor = B;
  } else {
    // If A and B have different parity, then we have an even number of numbers in the range [A, B].
    // So, we can pair them up and XOR them, leaving us with 0.
    xor = 0;
  }

  printf("%d\n", xor);
  return 0;
}