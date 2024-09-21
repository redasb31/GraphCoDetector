#include <stdio.h>
#include <stdlib.h>

#define MAX_UNITS 8
#define MAX_ROADS 18
#define MAX_TOWNS 36

// Structure to represent a town
typedef struct {
  int x, y;
} Town;

// Structure to represent a road
typedef struct {
  Town start, end;
} Road;

// Structure to represent a unit
typedef struct {
  int group; // 0 for ACM, 1 for ICPC
  Town location;
  Town target;
} Unit;

// Function to find the index of a town in the towns array
int findTownIndex(Town town, Town towns[], int townCount) {
  for (int i = 0; i < townCount; i++) {
    if (towns[i].x == town.x && towns[i].y == town.y) {
      return i;
    }
  }
  return -1;
}

// Function to check if two towns are on the same road
int onSameRoad(Town town1, Town town2, Road roads[], int roadCount) {
  for (int i = 0; i < roadCount; i++) {
    if ((town1.x == roads[i].start.x && town2.x == roads[i].end.x) ||
        (town1.y == roads[i].start.y && town2.y == roads[i].end.y)) {
      return 1;
    }
  }
  return 0;
}

// Function to find the minimum number of orders required for disarmament
int disarmUnits(Unit units[], int unitCount, Road roads[], int roadCount, Town towns[], int townCount) {
  int orders = 0;
  int group = 0; // 0 for ACM, 1 for ICPC

  // Keep track of occupied towns
  int townOccupied[MAX_TOWNS] = {0};

  // Keep track of units that have been moved
  int unitMoved[MAX_UNITS] = {0};

  while (1) {
    // Find a unit that can be moved
    int unitIndex = -1;
    for (int i = 0; i < unitCount; i++) {
      if (unitMoved[i] == 0 && !townOccupied[findTownIndex(units[i].location, towns, townCount)]) {
        unitIndex = i;
        break;
      }
    }

    // If no unit can be moved, all units have been disarmed
    if (unitIndex == -1) {
      break;
    }

    // Move the unit
    units[unitIndex].location = units[unitIndex].target;
    townOccupied[findTownIndex(units[unitIndex].location, towns, townCount)] = 1;
    unitMoved[unitIndex] = 1;

    orders++;

    // Switch to the other group
    group = 1 - group;
  }

  return orders;
}

int main() {
  int n, mA, mI;
  Road roads[MAX_ROADS];
  Town towns[MAX_TOWNS];
  Unit units[MAX_UNITS];
  int townCount = 0;

  while (1) {
    scanf("%d %d %d", &n, &mA, &mI);

    // If the input is triple zeros, terminate the program
    if (n == 0 && mA == 0 && mI == 0) {
      break;
    }

    // Read road data
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d", &roads[i].start.x, &roads[i].start.y, &roads[i].end.x, &roads[i].end.y);

      // Add the endpoints of the road to the towns array
      int startIndex = findTownIndex(roads[i].start, towns, townCount);
      if (startIndex == -1) {
        towns[townCount++] = roads[i].start;
      }

      int endIndex = findTownIndex(roads[i].end, towns, townCount);
      if (endIndex == -1) {
        towns[townCount++] = roads[i].end;
      }
    }

    // Read ACM unit data
    for (int i = 0; i < mA; i++) {
      scanf("%d %d", &units[i].location.x, &units[i].location.y);
      scanf("%d %d", &units[i].target.x, &units[i].target.y);
      units[i].group = 0; // ACM
    }

    // Read ICPC unit data
    for (int i = mA; i < mA + mI; i++) {
      scanf("%d %d", &units[i].location.x, &units[i].location.y);
      scanf("%d %d", &units[i].target.x, &units[i].target.y);
      units[i].group = 1; // ICPC
    }

    // Calculate the minimum number of orders
    int orders = disarmUnits(units, mA + mI, roads, n, towns, townCount);

    // Print the result
    printf("%d\n", orders);
  }

  return 0;
}