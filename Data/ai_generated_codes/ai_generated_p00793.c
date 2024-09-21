#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Function to determine the winner based on distances
int findWinner(int icX, int icY, int pcX, int pcY, int acmX, int acmY, int jewelX, int jewelY) {
  double icDist = distance(icX, icY, jewelX, jewelY);
  double pcDist = distance(pcX, pcY, jewelX, jewelY);
  double acmDist = distance(acmX, acmY, jewelX, jewelY);

  // Check for ties and prioritize based on the order
  if (icDist == pcDist && icDist == acmDist) {
    return 3; // ACM wins in case of a three-way tie
  } else if (icDist == pcDist && icDist < acmDist) {
    return 2; // PC wins in case of a tie between IC and PC
  } else if (icDist < pcDist && icDist < acmDist) {
    return 1; // IC wins
  } else if (pcDist < icDist && pcDist < acmDist) {
    return 2; // PC wins
  } else {
    return 3; // ACM wins
  }
}

int main() {
  int icX, icY, pcX, pcY, acmX, acmY;
  int caseNum = 1;

  while (1) {
    scanf("%d %d %d %d %d %d", &icX, &icY, &pcX, &pcY, &acmX, &acmY);

    // Check for end of input
    if (icX == 0 && icY == 0 && pcX == 0 && pcY == 0 && acmX == 0 && acmY == 0) {
      break;
    }

    // Calculate the probability of IC winning
    double probability = 0.0;
    for (int jewelX = 0; jewelX <= 10000; jewelX++) {
      for (int jewelY = 0; jewelY <= 10000; jewelY++) {
        if (findWinner(icX, icY, pcX, pcY, acmX, acmY, jewelX, jewelY) == 1) {
          probability += 1.0 / (10000 * 10000);
        }
      }
    }

    printf("%d %.5lf\n", caseNum, probability);
    caseNum++;
  }

  return 0;
}