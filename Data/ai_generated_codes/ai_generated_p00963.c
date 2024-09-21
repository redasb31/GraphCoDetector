#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points on a line
double distance(double x1, double y1, double x2, double y2) {
  return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

// Function to determine the face a worm ends up on based on its initial direction and distance traveled
int get_face(char edge[3], int d, int l) {
  // Define the coordinates of the vertices of the tetrahedron
  double A[2] = {0.0, 0.0};
  double B[2] = {1.0, 0.0};
  double C[2] = {0.5, sqrt(3.0) / 2.0};
  double D[2] = {0.5, sqrt(3.0) / 6.0};

  // Calculate the angle of the initial direction
  double angle = (double)d * M_PI / 180.0;

  // Define the starting point based on the initial edge
  double start[2] = {A[0], A[1]};
  if (edge[0] == 'B') {
    start[0] = B[0];
    start[1] = B[1];
  } else if (edge[0] == 'C') {
    start[0] = C[0];
    start[1] = C[1];
  } else if (edge[0] == 'D') {
    start[0] = D[0];
    start[1] = D[1];
  }

  // Define the direction vector
  double direction[2] = {cos(angle), sin(angle)};

  // Calculate the end point of the worm's path
  double end[2] = {start[0] + l * direction[0], start[1] + l * direction[1]};

  // Determine the face the worm ends up on based on the end point
  if (end[1] > sqrt(3.0) / 2.0) {
    return 1; // Face opposite vertex A
  } else if (end[1] < sqrt(3.0) / 6.0) {
    return 2; // Face opposite vertex D
  } else if (end[0] < 0.0) {
    return 3; // Face opposite vertex B
  } else if (end[0] > 1.0) {
    return 4; // Face opposite vertex C
  } else {
    return -1; // Error: Worm didn't end on a face
  }
}

int main() {
  char edge_p[3], edge_q[3];
  int d_p, d_q, l_p, l_q;

  // Input the worm data
  scanf("%s %d %d", edge_p, &d_p, &l_p);
  scanf("%s %d %d", edge_q, &d_q, &l_q);

  // Determine the face each worm ends up on
  int face_p = get_face(edge_p, d_p, l_p);
  int face_q = get_face(edge_q, d_q, l_q);

  // Output the result
  if (face_p == face_q) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }

  return 0;
}