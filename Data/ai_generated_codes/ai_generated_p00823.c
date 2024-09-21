#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about an atom
typedef struct {
  char symbol[3]; // Store the atomic symbol (max 2 characters)
  int weight;     // Store the atomic weight
} Atom;

// Function to calculate the molecular weight of a molecule
int calculateMolecularWeight(char *formula, Atom *table, int tableSize) {
  int weight = 0;
  int i = 0;
  int count = 0;
  int multiplier = 1;

  // Iterate through the formula
  while (formula[i] != '\0') {
    // Check for an atomic symbol
    if (isalpha(formula[i])) {
      // Find the atom in the table
      int j;
      for (j = 0; j < tableSize; j++) {
        if (formula[i] == table[j].symbol[0] && (formula[i + 1] == table[j].symbol[1] || formula[i + 1] == '\0')) {
          // Add the atomic weight to the total
          weight += table[j].weight * multiplier;
          // Move to the next character
          i++;
          break;
        }
      }
      // If the atom is not found in the table
      if (j == tableSize) {
        return -1; // Indicate UNKNOWN
      }
    } else if (formula[i] == '(') {
      // Check for a parenthesized sub-formula
      count++;
    } else if (formula[i] == ')') {
      // Check for the end of a parenthesized sub-formula
      count--;
    } else if (isdigit(formula[i])) {
      // Check for a numerical multiplier
      multiplier = formula[i] - '0';
    }
    i++;
  }

  // Return the total molecular weight
  return weight;
}

int main() {
  Atom table[100]; // Array to store the atomic table
  int tableSize = 0;
  char line[81];  // Buffer to store the input line

  // Read the atomic table
  while (1) {
    // Read a line from the input
    if (fgets(line, 81, stdin) == NULL) {
      break;
    }
    // Check for the end of the first part
    if (strcmp(line, "END_OF_FIRST_PART\n") == 0) {
      break;
    }

    // Parse the line to extract the atomic symbol and weight
    sscanf(line, "%2s %d", table[tableSize].symbol, &table[tableSize].weight);

    // Increment the table size
    tableSize++;
  }

  // Read and process molecular formulas
  while (1) {
    // Read a line from the input
    if (fgets(line, 81, stdin) == NULL) {
      break;
    }
    // Check for the end of the input
    if (line[0] == '0') {
      break;
    }
    // Remove the newline character
    line[strcspn(line, "\n")] = 0;

    // Calculate the molecular weight
    int weight = calculateMolecularWeight(line, table, tableSize);

    // Print the result
    if (weight == -1) {
      printf("UNKNOWN\n");
    } else {
      printf("%d\n", weight);
    }
  }

  return 0;
}