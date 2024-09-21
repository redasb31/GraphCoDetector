#include <stdio.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1000
#define MAX_COMMAND_LENGTH 100

// Function prototypes
void forwardChar(char *text, int *cursor);
void forwardWord(char *text, int *cursor);
void backwardChar(char *text, int *cursor);
void backwardWord(char *text, int *cursor);
void insertText(char *text, int *cursor, char *newText);
void deleteChar(char *text, int *cursor);
void deleteWord(char *text, int *cursor);

int main() {
    int numTexts, numCommands;
    char text[MAX_TEXT_LENGTH + 1];
    char command[MAX_COMMAND_LENGTH + 1];
    int cursor;

    scanf("%d", &numTexts);

    while (numTexts--) {
        // Read initial text
        scanf("%s", text);
        cursor = 0; // Cursor starts at the beginning

        // Read number of commands
        scanf("%d", &numCommands);

        // Read and execute commands
        while (numCommands--) {
            scanf("%s", command);

            // Process commands
            if (strcmp(command, "forward") == 0) {
                scanf("%s", command);
                if (strcmp(command, "char") == 0) {
                    forwardChar(text, &cursor);
                } else if (strcmp(command, "word") == 0) {
                    forwardWord(text, &cursor);
                }
            } else if (strcmp(command, "backward") == 0) {
                scanf("%s", command);
                if (strcmp(command, "char") == 0) {
                    backwardChar(text, &cursor);
                } else if (strcmp(command, "word") == 0) {
                    backwardWord(text, &cursor);
                }
            } else if (strcmp(command, "insert") == 0) {
                char newText[MAX_COMMAND_LENGTH + 1];
                scanf("%s", newText);
                insertText(text, &cursor, newText);
            } else if (strcmp(command, "delete") == 0) {
                scanf("%s", command);
                if (strcmp(command, "char") == 0) {
                    deleteChar(text, &cursor);
                } else if (strcmp(command, "word") == 0) {
                    deleteWord(text, &cursor);
                }
            }
        }

        // Print the final text with cursor
        printf("%s^", text);
        printf("\n");
    }

    return 0;
}

// Move the cursor by one character to the right
void forwardChar(char *text, int *cursor) {
    if (*cursor < strlen(text) - 1) {
        (*cursor)++;
    }
}

// Move the cursor to the end of the leftmost word in the right
void forwardWord(char *text, int *cursor) {
    int i = *cursor;
    while (i < strlen(text) && (text[i] == ' ' || text[i] == '.' || text[i] == ',')) {
        i++;
    }
    if (i < strlen(text)) {
        *cursor = i;
        while (i < strlen(text) && (text[i] != ' ' && text[i] != '.' && text[i] != ',')) {
            i++;
        }
        *cursor = i;
    } else {
        *cursor = i;
    }
}

// Move the cursor by one character to the left
void backwardChar(char *text, int *cursor) {
    if (*cursor > 0) {
        (*cursor)--;
    }
}

// Move the cursor to the beginning of the rightmost word in the left
void backwardWord(char *text, int *cursor) {
    int i = *cursor;
    if (i > 0) {
        while (i > 0 && (text[i] == ' ' || text[i] == '.' || text[i] == ',')) {
            i--;
        }
        if (i > 0) {
            *cursor = i;
            while (i > 0 && (text[i] != ' ' && text[i] != '.' && text[i] != ',')) {
                i--;
            }
            *cursor = i;
        } else {
            *cursor = i;
        }
    }
}

// Insert new text at the cursor position
void insertText(char *text, int *cursor, char *newText) {
    int i;
    for (i = strlen(text); i >= *cursor; i--) {
        text[i + strlen(newText)] = text[i];
    }
    for (i = 0; i < strlen(newText); i++) {
        text[*cursor + i] = newText[i];
    }
    *cursor += strlen(newText);
}

// Delete the character right next to the cursor
void deleteChar(char *text, int *cursor) {
    if (*cursor < strlen(text) - 1) {
        int i;
        for (i = *cursor; i < strlen(text) - 1; i++) {
            text[i] = text[i + 1];
        }
        text[strlen(text) - 1] = '\0';
    }
}

// Delete the leftmost word in the right of the cursor
void deleteWord(char *text, int *cursor) {
    int i = *cursor;
    while (i < strlen(text) && (text[i] == ' ' || text[i] == '.' || text[i] == ',')) {
        i++;
    }
    if (i < strlen(text)) {
        int start = i;
        while (i < strlen(text) && (text[i] != ' ' && text[i] != '.' && text[i] != ',')) {
            i++;
        }
        for (int j = start; j < strlen(text); j++) {
            text[j] = text[i];
            i++;
        }
        text[strlen(text) - (i - start)] = '\0';
    }
}