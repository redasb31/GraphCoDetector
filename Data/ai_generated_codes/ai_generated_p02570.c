/*
 *  This program calculates whether Takahashi will arrive at his meeting point on time.
 *  
 *  Input:
 *    D: Distance to the meeting point (meters)
 *    T: Time to meet (minutes)
 *    S: Takahashi's speed (meters per minute)
 *
 *  Output:
 *    "Yes" if Takahashi will arrive on time
 *    "No" if Takahashi will be late
 */

#include <stdio.h>

int main() {
  int D, T, S; // Declare variables for distance, time, and speed

  // Read input from the user
  scanf("%d %d %d", &D, &T, &S); 

  // Calculate the time Takahashi needs to reach the meeting point
  double time_taken = (double) D / S; 

  // Check if Takahashi will arrive on time
  if (time_taken <= T) {
    printf("Yes\n"); 
  } else {
    printf("No\n"); 
  }

  return 0;
}