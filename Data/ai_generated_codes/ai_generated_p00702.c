#include <stdio.h>
#include <string.h>

// Define the Kan-character representations
const char* kan_chars[] = {
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
    "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
    "ld", "mb", "mp", "nc", "nd", "ng", "nt", "nw", "ps", "qu", "cw", "ts"
};

// Function to get the Kan-character representation for a given string
const char* get_kan_char(const char* str) {
    for (int i = 0; i < 38; i++) {
        if (strcmp(str, kan_chars[i]) == 0) {
            return kan_chars[i];
        }
    }
    return NULL;
}

// Function to find the longest possible Kan-character representation from left to right
const char* find_longest_kan_char(const char* str, int* len) {
    int max_len = 0;
    const char* longest_kan_char = NULL;

    for (int i = 0; i < 38; i++) {
        int str_len = strlen(kan_chars[i]);
        if (strncmp(str, kan_chars[i], str_len) == 0 && str_len > max_len) {
            max_len = str_len;
            longest_kan_char = kan_chars[i];
        }
    }

    *len = max_len;
    return longest_kan_char;
}

int main() {
    int num_lines;
    scanf("%d\n", &num_lines);

    // Initialize a 2D array to store the counts of each pair
    int pair_counts[38][38] = {0};

    // Loop through each line of input
    for (int i = 0; i < num_lines; i++) {
        char line[60];
        fgets(line, 60, stdin);

        // Iterate through the characters in the line
        for (int j = 0; j < strlen(line) - 1; j++) {
            // Find the longest Kan-character representation
            int kan_char_len;
            const char* kan_char1 = find_longest_kan_char(&line[j], &kan_char_len);

            // If a Kan-character is found, check the next Kan-character
            if (kan_char1 != NULL) {
                j += kan_char_len - 1;
                const char* kan_char2 = find_longest_kan_char(&line[j + 1], &kan_char_len);
                if (kan_char2 != NULL) {
                    // Increment the count for the pair
                    for (int k = 0; k < 38; k++) {
                        if (strcmp(kan_chars[k], kan_char1) == 0) {
                            for (int l = 0; l < 38; l++) {
                                if (strcmp(kan_chars[l], kan_char2) == 0) {
                                    pair_counts[k][l]++;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    j += kan_char_len - 1;
                }
            }
        }
    }

    // Print the output
    for (int i = 0; i < 38; i++) {
        // Find the Kan-character that occurs most often after the current Kan-character
        int max_count = 0;
        int max_index = 0;
        for (int j = 0; j < 38; j++) {
            if (pair_counts[i][j] > max_count) {
                max_count = pair_counts[i][j];
                max_index = j;
            }
        }

        printf("%s %s %d\n", kan_chars[i], kan_chars[max_index], max_count);
    }

    return 0;
}