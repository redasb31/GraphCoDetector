#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS 1e-9

typedef struct {
  double x, y;
} Point;

typedef struct {
  Point pos;
  double vx, vy;
} Ball;

// Calculates the distance between two points
double distance(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Checks if two balls collide
int check_collision(Ball a, Ball b, double r) {
  return distance(a.pos, b.pos) < 2 * r;
}

// Reflects the ball's velocity vector across a horizontal line
void reflect_horizontal(Ball *ball) {
  ball->vy = -ball->vy;
}

// Reflects the ball's velocity vector across a vertical line
void reflect_vertical(Ball *ball) {
  ball->vx = -ball->vx;
}

// Updates the ball's position and velocity based on collisions with the cushion
void update_position(Ball *ball, double w, double h, double r) {
  // Check for collisions with the horizontal cushions
  if (ball->pos.y - r <= 0 && ball->vy < 0) {
    reflect_horizontal(ball);
  } else if (ball->pos.y + r >= h && ball->vy > 0) {
    reflect_horizontal(ball);
  }

  // Check for collisions with the vertical cushions
  if (ball->pos.x - r <= 0 && ball->vx < 0) {
    reflect_vertical(ball);
  } else if (ball->pos.x + r >= w && ball->vx > 0) {
    reflect_vertical(ball);
  }

  // Update the ball's position based on its velocity
  ball->pos.x += ball->vx;
  ball->pos.y += ball->vy;
}

// Simulates the motion of the balls until the hit ball stops
int simulate(Ball *balls, int n, double w, double h, double r) {
  // Initialize the hit ball's distance traveled
  double distance_traveled = 0;

  // Iterate until the hit ball stops
  while (distance_traveled < 10000) {
    // Update the position of the hit ball
    update_position(&balls[0], w, h, r);

    // Increment the distance traveled by the hit ball
    distance_traveled += sqrt(balls[0].vx * balls[0].vx + balls[0].vy * balls[0].vy);

    // Check for collisions with other balls
    for (int i = 1; i < n; i++) {
      if (check_collision(balls[0], balls[i], r)) {
        return i; // Return the index of the first ball that collides with the hit ball
      }
    }
  }

  return -1; // No collisions were detected
}

int main() {
  int n, w, h, r, vx, vy;
  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    scanf("%d %d %d %d %d", &w, &h, &r, &vx, &vy);
    Ball balls[n];
    for (int i = 0; i < n; i++) {
      scanf("%lf %lf", &balls[i].pos.x, &balls[i].pos.y);
    }
    // Assign velocity to the hit ball (index 0)
    balls[0].vx = vx;
    balls[0].vy = vy;
    int collision_index = simulate(balls, n, w, h, r);
    printf("%d\n", collision_index);
  }
  return 0;
}