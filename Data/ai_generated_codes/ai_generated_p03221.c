#include <stdio.h>
#include <stdlib.h>

// Structure to store information about a city
typedef struct {
    int prefecture;
    int year;
} City;

// Function to convert an integer to a string with leading zeros
char *int_to_string(int num, int len) {
    char *str = malloc(len + 1);
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    sprintf(str, "%0*d", len, num);
    return str;
}

int main() {
    int N, M; // Number of prefectures and cities
    scanf("%d %d", &N, &M);

    // Create an array to store city information
    City cities[M];
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &cities[i].prefecture, &cities[i].year);
    }

    // Create an array to store the number of cities in each prefecture
    int prefecture_counts[N + 1] = {0}; // Initialize all counts to 0
    for (int i = 0; i < M; i++) {
        prefecture_counts[cities[i].prefecture]++;
    }

    // Assign ID numbers to each city
    for (int i = 0; i < M; i++) {
        // Get the prefecture and city count
        int prefecture = cities[i].prefecture;
        int count = prefecture_counts[prefecture];

        // Convert the prefecture and count to strings with leading zeros
        char *prefecture_str = int_to_string(prefecture, 6);
        char *count_str = int_to_string(count, 6);

        // Print the ID number
        printf("%s%s\n", prefecture_str, count_str);

        // Decrement the count for the current prefecture
        prefecture_counts[prefecture]--;

        // Free allocated memory
        free(prefecture_str);
        free(count_str);
    }

    return 0;
}