#include <stdio.h>

int main() {
  // n: number of conveyor lanes
  // m: number of robot arms
  int n, m;
  scanf("%d %d", &n, &m);

  // Create an array to store the positions of the robot arms.
  // Each element in the array represents a robot arm.
  // The first element is the x-coordinate of the robot arm,
  // and the second element is the lane number of the robot arm.
  int robot_arms[m][2];

  // Read the positions of the robot arms from the input.
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &robot_arms[i][0], &robot_arms[i][1]);
  }

  // Create an array to store the number of manufacturing lines that can deliver
  // goods to each storage room.
  int delivery_count[n];

  // Initialize the array to 0.
  for (int i = 0; i < n; i++) {
    delivery_count[i] = 0;
  }

  // Iterate over the robot arms and update the delivery count array.
  for (int i = 0; i < m; i++) {
    // The robot arm at position i can deliver goods to the lane
    // robot_arms[i][1] and robot_arms[i][1] + 1.
    // Increase the delivery count for these lanes.
    delivery_count[robot_arms[i][1]]++;
    delivery_count[robot_arms[i][1] + 1]++;
  }

  // Print the delivery count for each storage room.
  for (int i = 0; i < n; i++) {
    printf("%d ", delivery_count[i]);
  }

  return 0;
}