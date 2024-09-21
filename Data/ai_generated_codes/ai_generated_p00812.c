#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 80
#define MAX_TERMS 100
#define MAX_COEFF 1000000000

// Structure to represent a term in a polynomial
typedef struct {
  int coeff;
  char vars[27]; // Store variables and their powers
  int powers[27];
} Term;

// Structure to represent a polynomial
typedef struct {
  Term terms[MAX_TERMS];
  int termCount;
} Polynomial;

// Function to parse a term from a string
int parseTerm(char *str, Term *term, int *pos) {
  int i = 0, j = 0, coeff = 1, power = 1;
  char var = 0;

  // Parse the coefficient
  while (isdigit(str[*pos])) {
    coeff = coeff * 10 + (str[*pos] - '0');
    (*pos)++;
  }

  // Parse the variables and their powers
  while (str[*pos] != '\0' && str[*pos] != '+' && str[*pos] != '-' && str[*pos] != ')') {
    if (isalpha(str[*pos])) {
      var = str[*pos];
      term->vars[j] = var;
      (*pos)++;
      if (str[*pos] == '^') {
        (*pos)++;
        power = str[*pos] - '0';
        (*pos)++;
      }
      term->powers[j] = power;
      j++;
    } else {
      return 0; // Invalid term
    }
  }

  term->coeff = coeff;
  term->termCount = j;
  return 1; // Valid term
}

// Function to parse an expression and create a polynomial
Polynomial parseExpression(char *str) {
  Polynomial poly;
  poly.termCount = 0;
  int pos = 0;
  Term term;
  int sign = 1; // Sign of the term (+1 for positive, -1 for negative)

  // Iterate through the string, parsing terms
  while (str[pos] != '\0') {
    // Skip spaces
    while (str[pos] == ' ') {
      pos++;
    }

    // Parse the sign
    if (str[pos] == '+') {
      sign = 1;
      pos++;
    } else if (str[pos] == '-') {
      sign = -1;
      pos++;
    }

    // Parse the term
    if (parseTerm(str, &term, &pos)) {
      term.coeff *= sign;
      // Add the term to the polynomial
      poly.terms[poly.termCount++] = term;
    } else {
      // Invalid term, return an empty polynomial
      poly.termCount = 0;
      return poly;
    }
  }

  return poly;
}

// Function to simplify a polynomial by combining like terms
Polynomial simplifyPolynomial(Polynomial poly) {
  Polynomial simplifiedPoly;
  simplifiedPoly.termCount = 0;

  // Iterate through the terms of the polynomial
  for (int i = 0; i < poly.termCount; i++) {
    // Flag to indicate if the current term has been combined with another
    int combined = 0;

    // Iterate through the simplified polynomial
    for (int j = 0; j < simplifiedPoly.termCount; j++) {
      // Check if the terms are like terms
      if (poly.terms[i].termCount == simplifiedPoly.terms[j].termCount) {
        int k;
        for (k = 0; k < poly.terms[i].termCount; k++) {
          if (poly.terms[i].vars[k] != simplifiedPoly.terms[j].vars[k] ||
              poly.terms[i].powers[k] != simplifiedPoly.terms[j].powers[k]) {
            break;
          }
        }

        // If all variables and powers match, combine the terms
        if (k == poly.terms[i].termCount) {
          simplifiedPoly.terms[j].coeff += poly.terms[i].coeff;
          combined = 1;
          break;
        }
      }
    }

    // If the term has not been combined, add it to the simplified polynomial
    if (!combined) {
      simplifiedPoly.terms[simplifiedPoly.termCount++] = poly.terms[i];
    }
  }

  return simplifiedPoly;
}

// Function to compare two polynomials
int comparePolynomials(Polynomial poly1, Polynomial poly2) {
  // Check if the number of terms are different
  if (poly1.termCount != poly2.termCount) {
    return 0;
  }

  // Iterate through the terms and compare their coefficients and variables
  for (int i = 0; i < poly1.termCount; i++) {
    if (poly1.terms[i].coeff != poly2.terms[i].coeff ||
        poly1.terms[i].termCount != poly2.terms[i].termCount) {
      return 0;
    }
    for (int j = 0; j < poly1.terms[i].termCount; j++) {
      if (poly1.terms[i].vars[j] != poly2.terms[i].vars[j] ||
          poly1.terms[i].powers[j] != poly2.terms[i].powers[j]) {
        return 0;
      }
    }
  }

  return 1; // Polynomials are equal
}

int main() {
  char expression[MAX_LEN];
  char answer[MAX_LEN];
  Polynomial expectedPoly, studentPoly;

  while (1) {
    // Read the expected expression
    fgets(expression, MAX_LEN, stdin);
    if (expression[0] == '.') {
      printf(".\n");
      break;
    }

    // Parse the expected expression
    expectedPoly = parseExpression(expression);

    // Simplify the expected polynomial
    expectedPoly = simplifyPolynomial(expectedPoly);

    // Read student answers until a period is encountered
    while (1) {
      fgets(answer, MAX_LEN, stdin);
      if (answer[0] == '.') {
        break;
      }

      // Parse the student's answer
      studentPoly = parseExpression(answer);

      // Simplify the student's polynomial
      studentPoly = simplifyPolynomial(studentPoly);

      // Compare the student's polynomial with the expected polynomial
      if (comparePolynomials(expectedPoly, studentPoly)) {
        printf("yes\n");
      } else {
        printf("no\n");
      }
    }
  }

  return 0;
}