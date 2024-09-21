#include <stdio.h>
#include <stdlib.h>

// Structure to represent a passenger's travel section
typedef struct {
    int start;
    int end;
} Passenger;

// Function to compare two passengers based on their starting station
int compare_passengers(const void *a, const void *b) {
    Passenger *pa = (Passenger *)a;
    Passenger *pb = (Passenger *)b;
    return pa->start - pb->start;
}

// Function to calculate the number of seats required under policy 1
int policy1_seats(Passenger *passengers, int n) {
    int seats = 0;
    int current_end = 0; // Tracks the end of the latest reservation

    // Sort passengers by their starting station
    qsort(passengers, n, sizeof(Passenger), compare_passengers);

    for (int i = 0; i < n; i++) {
        // If the current passenger's starting station is before the current end
        // then they need a new seat
        if (passengers[i].start < current_end) {
            seats++;
        }
        // Update the current end to the latest passenger's end station
        current_end = passengers[i].end;
    }

    return seats;
}

// Function to calculate the number of seats required under policy 2
int policy2_seats(Passenger *passengers, int n) {
    int seats = 0;
    int last_end = 0; // Tracks the end of the latest assigned seat

    // Sort passengers by their starting station
    qsort(passengers, n, sizeof(Passenger), compare_passengers);

    for (int i = 0; i < n; i++) {
        // If the current passenger's starting station is before the last end
        // then they need a new seat
        if (passengers[i].start < last_end) {
            seats++;
        }
        // Update the last end to the current passenger's end station
        last_end = passengers[i].end;
    }

    return seats;
}

int main() {
    int n;
    scanf("%d", &n);

    Passenger *passengers = malloc(n * sizeof(Passenger));

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &passengers[i].start, &passengers[i].end);
    }

    int seats_policy1 = policy1_seats(passengers, n);
    int seats_policy2 = policy2_seats(passengers, n);

    printf("%d %d\n", seats_policy1, seats_policy2);

    free(passengers);

    return 0;
}