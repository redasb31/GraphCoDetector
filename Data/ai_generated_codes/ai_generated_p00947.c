#include <stdio.h>

// Function to calculate the check digit for a given basic ID number using the operation table
int calculateCheckDigit(int a, int b, int c, int d, int table[10][10]) {
  int e = table[0][a];
  e = table[e][b];
  e = table[e][c];
  e = table[e][d];
  return e;
}

// Function to check if a given SSN is valid using the operation table
int checkSSN(int a, int b, int c, int d, int e, int table[10][10]) {
  int checkValue = table[0][a];
  checkValue = table[checkValue][b];
  checkValue = table[checkValue][c];
  checkValue = table[checkValue][d];
  checkValue = table[checkValue][e];
  return checkValue;
}

int main() {
  int table[10][10];
  int count = 0; // Counter for basic ID numbers with undetected errors

  // Read the operation table from input
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      scanf("%d", &table[i][j]);
    }
  }

  // Check for each basic ID number from 0000 to 9999
  for (int basicID = 0; basicID <= 9999; basicID++) {
    int a = basicID / 1000;
    int b = (basicID % 1000) / 100;
    int c = (basicID % 100) / 10;
    int d = basicID % 10;
    int e = calculateCheckDigit(a, b, c, d, table);

    // Check for single digit alteration errors
    for (int i = 0; i < 10; i++) {
      int alteredID = basicID;
      if (i != a) {
        alteredID = (alteredID / 1000) * 1000 + i * 1000 + (alteredID % 1000);
        if (checkSSN(alteredID / 1000, (alteredID % 1000) / 100,
                    (alteredID % 100) / 10, alteredID % 10, e, table) == 0) {
          count++;
          break; // Move to the next basic ID if an error is detected
        }
      }
      if (i != b) {
        alteredID = (alteredID / 100) * 100 + i * 100 + (alteredID % 100);
        if (checkSSN(alteredID / 1000, (alteredID % 1000) / 100,
                    (alteredID % 100) / 10, alteredID % 10, e, table) == 0) {
          count++;
          break;
        }
      }
      if (i != c) {
        alteredID = (alteredID / 10) * 10 + i * 10 + (alteredID % 10);
        if (checkSSN(alteredID / 1000, (alteredID % 1000) / 100,
                    (alteredID % 100) / 10, alteredID % 10, e, table) == 0) {
          count++;
          break;
        }
      }
      if (i != d) {
        alteredID = (alteredID / 10) * 10 + i + (alteredID % 10);
        if (checkSSN(alteredID / 1000, (alteredID % 1000) / 100,
                    (alteredID % 100) / 10, alteredID % 10, e, table) == 0) {
          count++;
          break;
        }
      }
    }

    // Check for transposition errors
    if (b != c &&
        checkSSN(a, c, b, d, e, table) == 0) { // Swap b and c
      count++;
    }
    if (c != d &&
        checkSSN(a, b, d, c, e, table) == 0) { // Swap c and d
      count++;
    }
  }

  printf("%d\n", count);
  return 0;
}