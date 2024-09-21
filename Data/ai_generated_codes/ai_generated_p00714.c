#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 50
#define DEPTH 30

// Structure to store board information
typedef struct {
  int x; // x-position
  int h; // height
} Board;

// Structure to store faucet information
typedef struct {
  int x; // x-position
  int flow; // flow rate
} Faucet;

// Structure to store observation point information
typedef struct {
  int x; // x-position
  int t; // observation time
} Observation;

// Function to calculate the water level at a given x-position and time
double calculateWaterLevel(Board boards[], int nBoards, Faucet faucets[], int nFaucets, Observation observation) {
  // Calculate the total water volume poured into the tank
  double totalWaterVolume = 0;
  for (int i = 0; i < nFaucets; i++) {
    totalWaterVolume += faucets[i].flow * observation.t; 
  }

  // Calculate the total water volume that can be contained in the tank up to the given x-position
  double tankCapacity = observation.x * HEIGHT * DEPTH;

  // Check if the tank is already full
  if (totalWaterVolume >= WIDTH * HEIGHT * DEPTH) {
    return HEIGHT; // Tank is full, water level is at the height of the tank
  }

  // Calculate the water level for each section of the tank
  double currentWaterVolume = 0;
  double waterLevel = 0;
  for (int i = 0; i < nBoards; i++) {
    // Calculate the volume of water in the current section
    int sectionWidth = (i == 0) ? observation.x : (boards[i].x - boards[i - 1].x); 
    double sectionVolume = sectionWidth * HEIGHT * DEPTH;

    // Add the volume of water in the current section to the total volume
    currentWaterVolume += sectionVolume;

    // Check if the current section is completely filled
    if (currentWaterVolume >= totalWaterVolume) {
      // Calculate the water level in the current section
      waterLevel = (totalWaterVolume - (currentWaterVolume - sectionVolume)) / (sectionWidth * DEPTH) + boards[i].h;
      return waterLevel;
    }
  }

  // If the water level is higher than the highest board, calculate the water level in the last section
  int sectionWidth = (observation.x - boards[nBoards - 1].x);
  double sectionVolume = sectionWidth * HEIGHT * DEPTH;
  waterLevel = (totalWaterVolume - (currentWaterVolume + sectionVolume)) / (sectionWidth * DEPTH) + boards[nBoards - 1].h;
  return waterLevel;
}

int main() {
  int d;
  scanf("%d", &d);

  for (int i = 0; i < d; i++) {
    // Read the number of boards
    int nBoards;
    scanf("%d", &nBoards);

    // Allocate memory for the boards
    Board* boards = (Board*)malloc(nBoards * sizeof(Board));

    // Read the board information
    for (int j = 0; j < nBoards; j++) {
      scanf("%d %d", &boards[j].x, &boards[j].h);
    }

    // Read the number of faucets
    int nFaucets;
    scanf("%d", &nFaucets);

    // Allocate memory for the faucets
    Faucet* faucets = (Faucet*)malloc(nFaucets * sizeof(Faucet));

    // Read the faucet information
    for (int j = 0; j < nFaucets; j++) {
      scanf("%d %d", &faucets[j].x, &faucets[j].flow);
    }

    // Read the number of observation points
    int nObservations;
    scanf("%d", &nObservations);

    // Allocate memory for the observation points
    Observation* observations = (Observation*)malloc(nObservations * sizeof(Observation));

    // Read the observation point information
    for (int j = 0; j < nObservations; j++) {
      scanf("%d %d", &observations[j].x, &observations[j].t);
    }

    // Calculate and print the water level for each observation point
    for (int j = 0; j < nObservations; j++) {
      double waterLevel = calculateWaterLevel(boards, nBoards, faucets, nFaucets, observations[j]);
      printf("%.3lf\n", waterLevel);
    }

    // Free allocated memory
    free(boards);
    free(faucets);
    free(observations);
  }

  return 0;
}