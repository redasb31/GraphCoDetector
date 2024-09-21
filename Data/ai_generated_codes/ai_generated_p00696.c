#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print a single column
void print_column(char *text, int plen, int width, int cspace) {
    int i, j, k, line_count = 0, text_len = strlen(text);
    char *line = (char *)malloc(width + 1);
    
    // Iterate through the text line by line
    for (i = 0; i < text_len; i += width) {
        // Copy a chunk of text to the current line
        for (j = 0, k = i; j < width && k < text_len; j++, k++) {
            line[j] = text[k];
        }
        line[j] = '\0';

        // Print the current line, padding with dots if necessary
        printf("%s", line);
        for (j = strlen(line); j < width; j++) {
            printf(".");
        }
        printf("%*c", cspace, ' '); 

        line_count++;
        // Check if we've reached the desired line count for the column
        if (line_count == plen) {
            printf("\n");
            line_count = 0;
        }
    }

    // Print any remaining lines with dots
    while (line_count < plen) {
        for (j = 0; j < width; j++) {
            printf(".");
        }
        printf("%*c", cspace, ' '); 
        line_count++;
        if (line_count == plen) {
            printf("\n");
            line_count = 0;
        }
    }

    free(line);
}

// Function to print a formatted page
void print_page(char *text, int plen, int cnum, int width, int cspace) {
    int i, text_len = strlen(text);
    char *column_text = (char *)malloc(text_len + 1);

    // Iterate through the text, dividing it into columns
    for (i = 0; i < cnum; i++) {
        strncpy(column_text, text + i * (width + cspace), text_len - i * (width + cspace));
        column_text[text_len - i * (width + cspace)] = '\0';
        print_column(column_text, plen, width, cspace);
    }

    free(column_text);
}

int main() {
    int plen, cnum, width, cspace;
    char *text = NULL;
    size_t text_len = 0;
    char line[1001];

    while (1) {
        // Read input parameters
        if (scanf("%d", &plen) != 1) {
            break; // Exit loop if no input is read
        }
        scanf("%d %d %d", &cnum, &width, &cspace);

        // Read input text line by line
        while (fgets(line, 1001, stdin) != NULL) {
            // Exit text reading loop if line is '?'
            if (strcmp(line, "?\n") == 0) {
                break;
            }
            text_len += strlen(line);
            text = (char *)realloc(text, text_len + 1);
            strcat(text, line);
        }

        // Print the formatted page
        print_page(text, plen, cnum, width, cspace);
        printf("#\n");
        printf("?\n");
        free(text);
        text = NULL;
        text_len = 0;
    }
    return 0;
}