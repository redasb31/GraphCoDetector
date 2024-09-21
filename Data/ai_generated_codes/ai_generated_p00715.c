#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STREETS 200
#define MAX_CROSSINGS 1000
#define MAX_STRING_LEN 16

typedef struct {
  char name[MAX_STRING_LEN + 1];
  int is_north_south;
  int strength;
} Street;

typedef struct {
  Street *streets[MAX_STREETS];
  int num_streets;
} City;

// Function prototypes
City *create_city();
void add_street(City *city, char *name, int is_north_south);
void add_crossing(City *city, char *street1, char *street2);
int find_street(City *city, char *name);
int is_orthogonal(City *city, char *street1, char *street2);
int has_equal_strength(City *city, char *street1, char *street2);
int is_stronger(City *city, char *street1, char *street2);
void print_city(City *city);

int main() {
  int N, M, i;
  char crossing[MAX_STRING_LEN + 1];
  char question[MAX_STRING_LEN + 1];

  while (1) {
    scanf("%d", &N);

    if (N == 0) {
      break;
    }

    City *city = create_city();

    // Read crossing information
    for (i = 0; i < N; i++) {
      scanf("%s", crossing);

      char *street1 = strtok(crossing, "-");
      char *street2 = strtok(NULL, "-");

      add_crossing(city, street1, street2);
    }

    // Read questions
    scanf("%d", &M);
    for (i = 0; i < M; i++) {
      scanf("%s", question);

      char *street1 = strtok(question, "-");
      char *street2 = strtok(NULL, "-");

      if (is_orthogonal(city, street1, street2) && is_stronger(city, street1, street2)) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }

    // Print the number of streets
    printf("%d\n", city->num_streets);

    // Free memory
    free(city);
  }

  return 0;
}

// Create a new city with no streets
City *create_city() {
  City *city = malloc(sizeof(City));
  city->num_streets = 0;
  return city;
}

// Add a new street to the city
void add_street(City *city, char *name, int is_north_south) {
  city->streets[city->num_streets] = malloc(sizeof(Street));
  strcpy(city->streets[city->num_streets]->name, name);
  city->streets[city->num_streets]->is_north_south = is_north_south;
  city->streets[city->num_streets]->strength = 0;
  city->num_streets++;
}

// Add a crossing to the city
void add_crossing(City *city, char *street1, char *street2) {
  int index1 = find_street(city, street1);
  int index2 = find_street(city, street2);

  // If either street does not exist, add it
  if (index1 == -1) {
    add_street(city, street1, !city->streets[index2]->is_north_south);
    index1 = city->num_streets - 1;
  }
  if (index2 == -1) {
    add_street(city, street2, !city->streets[index1]->is_north_south);
    index2 = city->num_streets - 1;
  }
}

// Find a street in the city by name
int find_street(City *city, char *name) {
  for (int i = 0; i < city->num_streets; i++) {
    if (strcmp(city->streets[i]->name, name) == 0) {
      return i;
    }
  }
  return -1;
}

// Check if two streets are orthogonal
int is_orthogonal(City *city, char *street1, char *street2) {
  int index1 = find_street(city, street1);
  int index2 = find_street(city, street2);

  if (index1 == -1 || index2 == -1) {
    return 0;
  }

  return city->streets[index1]->is_north_south != city->streets[index2]->is_north_south;
}

// Check if two streets have equal strength
int has_equal_strength(City *city, char *street1, char *street2) {
  int index1 = find_street(city, street1);
  int index2 = find_street(city, street2);

  if (index1 == -1 || index2 == -1) {
    return 0;
  }

  // Check if they cross the same third street
  for (int i = 0; i < city->num_streets; i++) {
    if (i != index1 && i != index2 && 
        (strcmp(city->streets[i]->name, street1) != 0 && 
         strcmp(city->streets[i]->name, street2) != 0) &&
        (strcmp(city->streets[index1]->name, city->streets[i]->name) != 0 || 
         strcmp(city->streets[index2]->name, city->streets[i]->name) != 0)) {
      return 0;
    }
  }

  // Check if there is no street D such that D-A and B-D appear in the input
  for (int i = 0; i < city->num_streets; i++) {
    if (i != index1 && i != index2 &&
        (strcmp(city->streets[i]->name, street1) != 0 && 
         strcmp(city->streets[i]->name, street2) != 0) &&
        (strcmp(city->streets[i]->name, street1) == 0 || 
         strcmp(city->streets[i]->name, street2) == 0)) {
      return 0;
    }
  }

  // Check if there is no street E such that A-E and E-B appear in the input
  for (int i = 0; i < city->num_streets; i++) {
    if (i != index1 && i != index2 &&
        (strcmp(city->streets[i]->name, street1) != 0 && 
         strcmp(city->streets[i]->name, street2) != 0) &&
        (strcmp(city->streets[i]->name, street1) == 0 || 
         strcmp(city->streets[i]->name, street2) == 0)) {
      return 0;
    }
  }

  return 1;
}

// Check if street1 is stronger than street2
int is_stronger(City *city, char *street1, char *street2) {
  int index1 = find_street(city, street1);
  int index2 = find_street(city, street2);

  if (index1 == -1 || index2 == -1) {
    return 0;
  }

  // If they have equal strength, return true
  if (has_equal_strength(city, street1, street2)) {
    return 1;
  }

  // Find all streets with equal strength to street1
  for (int i = 0; i < city->num_streets; i++) {
    if (has_equal_strength(city, street1, city->streets[i]->name)) {
      city->streets[i]->strength = city->streets[index1]->strength;
    }
  }

  // Find all streets with equal strength to street2
  for (int i = 0; i < city->num_streets; i++) {
    if (has_equal_strength(city, street2, city->streets[i]->name)) {
      city->streets[i]->strength = city->streets[index2]->strength;
    }
  }

  // Check if street1 is stronger than street2
  if (city->streets[index1]->strength > city->streets[index2]->strength) {
    return 1;
  }

  // Find a sequence of streets connecting street1 to street2
  for (int i = 0; i < city->num_streets; i++) {
    if (i != index1 && i != index2) {
      // If street1 has equal strength to street i
      if (city->streets[i]->strength == city->streets[index1]->strength &&
          // And street i has equal strength to street2
          city->streets[i]->strength == city->streets[index2]->strength) {
        // Then street1 is stronger than street2
        return 1;
      }
    }
  }

  return 0;
}

// Print the city information for debugging
void print_city(City *city) {
  for (int i = 0; i < city->num_streets; i++) {
    printf("%s: %s, strength: %d\n", city->streets[i]->name, city->streets[i]->is_north_south ? "NS" : "EW", city->streets[i]->strength);
  }
}