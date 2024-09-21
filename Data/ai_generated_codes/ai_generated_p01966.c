#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int a; // start point
  int b; // goal point
  int p; // number of products
  int t; // time to start putting products
} Request;

// Function to compare two requests based on their start time
int compare_requests(const void *a, const void *b) {
  Request *req1 = (Request *)a;
  Request *req2 = (Request *)b;
  return req1->t - req2->t;
}

// Function to calculate the minimum time to complete all the requests
int calculate_min_time(Request *requests, int n, int N) {
  int time = 0; // Current time
  int i = 0; // Index of the current request
  int current_position = 1; // Current position of the plate on the conveyor belt
  int num_products = 0; // Number of products currently being transported

  while (i < n) {
    // If the current request can be started at the current time
    if (requests[i].t == time) {
      // Put products on the belt
      num_products += requests[i].p;
      i++;
    }

    // If products are being transported
    if (num_products > 0) {
      // Move the plate to the next position
      current_position++;
      // If the plate reaches the goal point of a product, remove it
      if (current_position == requests[i - 1].b) {
        num_products -= requests[i - 1].p;
      }
    } else {
      // If no products are being transported, move the plate to the next position
      current_position++;
    }

    // Update time
    time++;
  }

  return time;
}

int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);

  // Allocate memory for the requests
  Request *requests = malloc(sizeof(Request) * Q);

  // Read the requests
  for (int i = 0; i < Q; i++) {
    scanf("%d %d %d", &requests[i].a, &requests[i].b, &requests[i].p);
    requests[i].t = requests[i].a - 1; // Calculate the start time of the request
  }

  // Sort the requests by start time
  qsort(requests, Q, sizeof(Request), compare_requests);

  // Calculate and print the minimum time for each prefix of requests
  for (int i = 1; i <= Q; i++) {
    printf("%d\n", calculate_min_time(requests, i, N));
  }

  // Free the memory
  free(requests);

  return 0;
}