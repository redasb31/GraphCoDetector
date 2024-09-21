#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_COUNTRIES 35
#define MAX_VERTICES 50
#define EPSILON 1e-6

typedef struct {
  int x;
  int y;
} Point;

typedef struct {
  int n;
  Point vertices[MAX_VERTICES];
} Country;

// Function to calculate the cross product of two vectors
double cross_product(Point a, Point b, Point c) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Function to check if a point is inside a polygon
int is_point_inside_polygon(Point point, Country country) {
  int i, j;
  int crossings = 0;
  for (i = 0, j = country.n - 1; i < country.n; j = i++) {
    if (((country.vertices[i].y <= point.y && country.vertices[j].y > point.y) ||
        (country.vertices[i].y > point.y && country.vertices[j].y <= point.y)) &&
        (point.x < (country.vertices[j].x - country.vertices[i].x) * (point.y - country.vertices[i].y) /
                    (country.vertices[j].y - country.vertices[i].y) +
            country.vertices[i].x)) {
      crossings++;
    }
  }
  return crossings % 2 == 1;
}

// Function to check if two segments intersect
int segments_intersect(Point a, Point b, Point c, Point d) {
  double d1 = cross_product(a, b, c);
  double d2 = cross_product(a, b, d);
  double d3 = cross_product(c, d, a);
  double d4 = cross_product(c, d, b);
  return (d1 * d2 < 0 && d3 * d4 < 0);
}

// Function to check if two countries are adjacent
int are_countries_adjacent(Country country1, Country country2) {
  int i, j;
  for (i = 0; i < country1.n; i++) {
    for (j = 0; j < country2.n; j++) {
      if (segments_intersect(
              country1.vertices[i],
              country1.vertices[(i + 1) % country1.n],
              country2.vertices[j],
              country2.vertices[(j + 1) % country2.n])) {
        return 1;
      }
    }
  }
  return 0;
}

// Function to calculate the minimum number of colors required to paint the map
int min_colors(Country countries[], int n) {
  int i, j;
  int colors[MAX_COUNTRIES];
  for (i = 0; i < n; i++) {
    colors[i] = 0;
  }

  // Assign color 1 to the first country
  colors[0] = 1;

  // Assign colors to the remaining countries
  for (i = 1; i < n; i++) {
    // Check if the current country is adjacent to any previously colored country
    int is_adjacent = 0;
    for (j = 0; j < i; j++) {
      if (are_countries_adjacent(countries[i], countries[j])) {
        is_adjacent = 1;
        if (colors[i] == 0) {
          colors[i] = colors[j];
        } else if (colors[i] != colors[j]) {
          // If the current country is adjacent to a country with the same color,
          // increment the color counter for all countries with the same color
          for (int k = 0; k < i; k++) {
            if (colors[k] == colors[i]) {
              colors[k]++;
            }
          }
        }
      }
    }

    // If the current country is not adjacent to any previously colored country,
    // assign it a new color
    if (!is_adjacent && colors[i] == 0) {
      colors[i] = colors[i - 1] + 1;
    }
  }

  // Find the maximum color assigned
  int max_color = 0;
  for (i = 0; i < n; i++) {
    if (colors[i] > max_color) {
      max_color = colors[i];
    }
  }

  return max_color;
}

int main() {
  int n, m, i, j;
  Country countries[MAX_COUNTRIES];

  while (1) {
    scanf("%d", &n);
    if (n == 0) {
      break;
    }

    for (i = 0; i < n; i++) {
      scanf("%d", &m);
      countries[i].n = m;
      for (j = 0; j < m; j++) {
        scanf("%d %d", &countries[i].vertices[j].x, &countries[i].vertices[j].y);
      }
    }

    printf("%d\n", min_colors(countries, n));
  }

  return 0;
}