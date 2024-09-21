#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000
#define MAX_M 40
#define MAX_D 1000000000000

typedef struct {
  long long x, y;
} Point;

Point points[MAX_N];

int N;

// Function to check if two points are the same
int is_same_point(Point a, Point b) {
  return (a.x == b.x && a.y == b.y);
}

// Function to check if a point is within the reachable range of the robot arm
int is_reachable(Point target, long long *d, int m, char *w) {
  Point current = {0, 0};
  for (int i = 0; i < m; i++) {
    switch (w[i]) {
      case 'L':
        current.x -= d[i];
        break;
      case 'R':
        current.x += d[i];
        break;
      case 'D':
        current.y -= d[i];
        break;
      case 'U':
        current.y += d[i];
        break;
    }
  }
  return is_same_point(current, target);
}

// Function to find the shortest path to reach a target point
char *find_path(Point target, long long *d, int m) {
  char *path = malloc(sizeof(char) * (m + 1));
  if (path == NULL) {
    return NULL;
  }
  path[m] = '\0';
  Point current = {0, 0};
  for (int i = 0; i < m; i++) {
    if (target.x > current.x) {
      path[i] = 'R';
      current.x += d[i];
    } else if (target.x < current.x) {
      path[i] = 'L';
      current.x -= d[i];
    } else if (target.y > current.y) {
      path[i] = 'U';
      current.y += d[i];
    } else if (target.y < current.y) {
      path[i] = 'D';
      current.y -= d[i];
    } else {
      // Target point is already reached
      break;
    }
  }
  return path;
}

// Function to find the robot arm configuration that can reach all target points
int find_arm(int *m, long long *d, char **paths) {
  // Check if all points are on the same horizontal or vertical line
  long long x = points[0].x;
  long long y = points[0].y;
  int same_x = 1, same_y = 1;
  for (int i = 1; i < N; i++) {
    if (points[i].x != x) {
      same_x = 0;
    }
    if (points[i].y != y) {
      same_y = 0;
    }
  }

  // If all points are on the same horizontal line, create a horizontal robot arm
  if (same_x && !same_y) {
    *m = 1;
    d[0] = abs(points[0].y - points[N - 1].y);
    for (int i = 0; i < N; i++) {
      if (points[i].y > points[0].y) {
        paths[i][0] = 'U';
      } else {
        paths[i][0] = 'D';
      }
    }
    return 1;
  }

  // If all points are on the same vertical line, create a vertical robot arm
  if (!same_x && same_y) {
    *m = 1;
    d[0] = abs(points[0].x - points[N - 1].x);
    for (int i = 0; i < N; i++) {
      if (points[i].x > points[0].x) {
        paths[i][0] = 'R';
      } else {
        paths[i][0] = 'L';
      }
    }
    return 1;
  }

  // If all points are not on the same line, check if a robot arm with 2 sections can reach all points
  if (same_x || same_y) {
    *m = 2;
    d[0] = abs(points[0].x - points[1].x);
    d[1] = abs(points[0].y - points[1].y);
    for (int i = 0; i < N; i++) {
      if (points[i].x > points[0].x) {
        paths[i][0] = 'R';
      } else if (points[i].x < points[0].x) {
        paths[i][0] = 'L';
      }
      if (points[i].y > points[0].y) {
        paths[i][1] = 'U';
      } else if (points[i].y < points[0].y) {
        paths[i][1] = 'D';
      }
    }
    return 1;
  }

  // If a robot arm with 2 sections cannot reach all points, try a robot arm with 3 sections
  *m = 3;
  d[0] = abs(points[0].x - points[1].x);
  d[1] = abs(points[0].y - points[1].y);
  d[2] = abs(points[0].x - points[2].x);
  for (int i = 0; i < N; i++) {
    if (points[i].x > points[0].x) {
      paths[i][0] = 'R';
      paths[i][1] = 'L';
      paths[i][2] = 'R';
    } else if (points[i].x < points[0].x) {
      paths[i][0] = 'L';
      paths[i][1] = 'R';
      paths[i][2] = 'L';
    } else {
      paths[i][0] = 'L';
      paths[i][1] = 'R';
      paths[i][2] = 'R';
    }
    if (points[i].y > points[0].y) {
      paths[i][1] = 'U';
    } else if (points[i].y < points[0].y) {
      paths[i][1] = 'D';
    }
  }
  return 1;
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%lld %lld", &points[i].x, &points[i].y);
  }

  int m;
  long long d[MAX_M];
  char *paths[MAX_N];

  // Find the robot arm configuration that can reach all target points
  if (!find_arm(&m, d, paths)) {
    printf("-1\n");
    return 0;
  }

  // Output the robot arm configuration
  printf("%d\n", m);
  for (int i = 0; i < m; i++) {
    printf("%lld ", d[i]);
  }
  printf("\n");

  // Output the path to each target point
  for (int i = 0; i < N; i++) {
    paths[i] = find_path(points[i], d, m);
    printf("%s\n", paths[i]);
    free(paths[i]);
  }

  return 0;
}