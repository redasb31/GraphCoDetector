#include <stdio.h>
#include <string.h>

#define MOD 1000000007

int main() {
  char a[51], b[51], c[51];
  while (scanf("%s %s %s", a, b, c) == 3 && strcmp(a, "0") != 0) {
    // Calculate the number of question marks in each string.
    int a_qm = 0, b_qm = 0, c_qm = 0;
    for (int i = 0; a[i] != '\0'; i++) {
      if (a[i] == '?') {
        a_qm++;
      }
    }
    for (int i = 0; b[i] != '\0'; i++) {
      if (b[i] == '?') {
        b_qm++;
      }
    }
    for (int i = 0; c[i] != '\0'; i++) {
      if (c[i] == '?') {
        c_qm++;
      }
    }

    // Calculate the number of possible assignments.
    long long count = 1;
    for (int i = 0; i < a_qm + b_qm + c_qm; i++) {
      count = (count * 10) % MOD;
    }

    // Handle cases where there are no question marks or too many question marks.
    if (a_qm == 0 && b_qm == 0 && c_qm == 0) {
      if (atoi(a) + atoi(b) == atoi(c)) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else if (a_qm + b_qm != c_qm) {
      printf("0\n");
    } else {
      // Reduce the number of possible assignments based on carry-over possibilities.
      int carry = 0;
      for (int i = strlen(a) - 1; i >= 0; i--) {
        int a_digit = a[i] == '?' ? 0 : a[i] - '0';
        int b_digit = b[i] == '?' ? 0 : b[i] - '0';
        int c_digit = c[i] == '?' ? 0 : c[i] - '0';
        
        if (a[i] == '?' && b[i] == '?' && c[i] == '?') {
          // All digits are unknown, so there are 10 possible assignments for each.
          count = (count * 10) % MOD;
        } else if (a[i] == '?' && b[i] == '?') {
          // Only the digit in c is known.
          count = (count * (c_digit + carry)) % MOD;
          if (c_digit + carry >= 10) {
            carry = 1;
          } else {
            carry = 0;
          }
        } else if (a[i] == '?' && c[i] == '?') {
          // Only the digit in b is known.
          count = (count * (10 - b_digit - carry)) % MOD;
          if (10 - b_digit - carry < 0) {
            carry = 1;
          } else {
            carry = 0;
          }
        } else if (b[i] == '?' && c[i] == '?') {
          // Only the digit in a is known.
          count = (count * (10 - a_digit - carry)) % MOD;
          if (10 - a_digit - carry < 0) {
            carry = 1;
          } else {
            carry = 0;
          }
        } else if (a[i] == '?') {
          // Only the digits in b and c are known.
          count = (count * ((c_digit + carry - b_digit) % 10)) % MOD;
          if (c_digit + carry - b_digit >= 10) {
            carry = 1;
          } else {
            carry = 0;
          }
        } else if (b[i] == '?') {
          // Only the digits in a and c are known.
          count = (count * ((c_digit + carry - a_digit) % 10)) % MOD;
          if (c_digit + carry - a_digit >= 10) {
            carry = 1;
          } else {
            carry = 0;
          }
        } else if (c[i] == '?') {
          // Only the digits in a and b are known.
          count = (count * ((a_digit + b_digit + carry) % 10)) % MOD;
          if (a_digit + b_digit + carry >= 10) {
            carry = 1;
          } else {
            carry = 0;
          }
        }
      }

      // Check if the carry-over is consistent with the first digits.
      if (carry == 1 && (a[0] == '?' || b[0] == '?' || c[0] == '?')) {
        count = 0;
      }

      printf("%lld\n", count);
    }
  }
  return 0;
}