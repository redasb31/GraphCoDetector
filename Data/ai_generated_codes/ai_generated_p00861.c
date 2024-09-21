#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_PROGRAM_LINES 1000

// Structure to represent an array
typedef struct {
  int length;
  int *values;
  int initialized; // Flag to track if any element has been assigned
} Array;

// Function to create a new array
Array* createArray(int length) {
  Array *arr = (Array*)malloc(sizeof(Array));
  arr->length = length;
  arr->values = (int*)calloc(length, sizeof(int));
  arr->initialized = 0;
  return arr;
}

// Function to free an array
void freeArray(Array *arr) {
  free(arr->values);
  free(arr);
}

// Function to get the value of an array element
int getArrayValue(Array *arr, int index) {
  if (index < 0 || index >= arr->length) {
    return -1; // Indicate an invalid index
  }
  return arr->values[index];
}

// Function to set the value of an array element
void setArrayValue(Array *arr, int index, int value) {
  if (index < 0 || index >= arr->length) {
    return; // Do nothing if the index is invalid
  }
  arr->values[index] = value;
  arr->initialized = 1;
}

// Function to evaluate an expression
int evaluateExpression(char *expression, Array *arrays, int numArrays) {
  int value = 0;
  if (sscanf(expression, "%d", &value) == 1) {
    return value; // Expression is a number
  } else {
    char arrayName[MAX_LINE_LENGTH];
    int index;
    if (sscanf(expression, "%[^[][%d]", arrayName, &index) == 2) {
      // Expression is an array element
      for (int i = 0; i < numArrays; i++) {
        if (strcmp(arrayName, arrays[i].values) == 0) {
          // Found the array
          return getArrayValue(&arrays[i], index);
        }
      }
    }
  }
  return -1; // Expression evaluation error
}

// Function to process an assignment statement
int processAssignment(char *line, Array *arrays, int numArrays) {
  char arrayName[MAX_LINE_LENGTH];
  int index, value;
  if (sscanf(line, "%[^[][%d]=%d", arrayName, &index, &value) == 3) {
    // Assignment of a number to an array element
    for (int i = 0; i < numArrays; i++) {
      if (strcmp(arrayName, arrays[i].values) == 0) {
        // Found the array
        setArrayValue(&arrays[i], index, value);
        return 0; // No bug found
      }
    }
  } else if (sscanf(line, "%[^[][%d]=%[^[][%d]", arrayName, &index, arrayName, &value) == 4) {
    // Assignment of an array element to another array element
    for (int i = 0; i < numArrays; i++) {
      if (strcmp(arrayName, arrays[i].values) == 0) {
        // Found the array
        value = evaluateExpression(line + strlen(arrayName) + 1, arrays, numArrays);
        if (value != -1) {
          setArrayValue(&arrays[i], index, value);
          return 0; // No bug found
        } else {
          return -1; // Bug: Invalid array access or uninitialized value
        }
      }
    }
  }
  return -1; // Syntax error or other errors
}

int main() {
  char line[MAX_LINE_LENGTH];
  Array *arrays = NULL;
  int numArrays = 0;
  int lineNum = 1;
  int bugLine = 0;

  while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) {
    line[strcspn(line, "\n")] = 0; // Remove trailing newline

    if (line[0] == '.') {
      // End of program
      if (arrays != NULL) {
        for (int i = 0; i < numArrays; i++) {
          freeArray(&arrays[i]);
        }
        free(arrays);
      }
      arrays = NULL;
      numArrays = 0;
      lineNum = 1;
      bugLine = 0;
      if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
        break; // End of input
      }
      continue; // Start processing a new program
    }

    if (bugLine == 0) { // Only process lines if no bug found yet
      char arrayName[MAX_LINE_LENGTH];
      int length;
      if (sscanf(line, "%[^[][%d]", arrayName, &length) == 2) {
        // Declaration
        arrays = (Array*)realloc(arrays, (numArrays + 1) * sizeof(Array));
        arrays[numArrays] = *createArray(length);
        strcpy(arrays[numArrays].values, arrayName);
        numArrays++;
      } else {
        // Assignment or other statement
        if (line[0] == 'a' || line[0] == 'b' || line[0] == 'g' || line[0] == 'x' || line[0] == 'G' || line[0] == 'B') {
          // Check for potential bug in assignment
          int result = processAssignment(line, arrays, numArrays);
          if (result == -1) {
            // Bug found
            bugLine = lineNum;
          }
        }
      }
      lineNum++;
    }
  }

  printf("%d\n", bugLine);

  return 0;
}