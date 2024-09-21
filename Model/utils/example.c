#include <stdio.h>
#include <math.h>

/*
This C code calculates whether a spherical cheese can fit through a cylindrical hole.
*/

int main() {
  int A, B, C, n, R;

  // Loop through each dataset until three zeros are encountered
  while (1) {
    scanf("%d %d %d", &A, &B, &C);
    
    // End of input
    if (A == 0 && B == 0 && C == 0) {
      break;
    }

    scanf("%d", &n);

    // Loop through each hole in the dataset
    for (int i = 0; i < n; i++) {
      scanf("%d", &R);

      // Calculate the diagonal of the cheese
      double diagonal = sqrt(A * A + B * B + C * C);

      // Check if the diagonal is smaller than the radius of the hole
      if (diagonal < R) {
        printf("OK\n");
      } else {
        printf("NA\n");
      }
    }
  }

  return 0;
}


//In essence, the code determines if the cheese can fit through the hole by comparing its diagonal (the longest possible dimension) to the radius of the hole. If the diagonal is smaller, it can fit; otherwise, it cannot.
