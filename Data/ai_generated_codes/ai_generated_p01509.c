#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to store information about a note
typedef struct Note {
    char note; // 'C', 'D', 'E', 'F', 'G', 'A', 'B'
    int octave; // 1-8
    int duration; // 1, 2, 4, 8, 16, 32, 64, 128
    int dots; // Number of dots
} Note;

// Structure to store information about a rest
typedef struct Rest {
    int duration; // 1, 2, 4, 8, 16, 32, 64, 128
    int dots; // Number of dots
} Rest;

// Function to calculate the duration of a note or rest
int calculateDuration(int duration, int dots) {
    int totalDuration = duration;
    for (int i = 0; i < dots; i++) {
        totalDuration += duration >> (i + 1);
    }
    return totalDuration;
}

// Function to compare two notes based on their duration
int compareNoteDuration(const void *a, const void *b) {
    Note *noteA = (Note *)a;
    Note *noteB = (Note *)b;
    return calculateDuration(noteA->duration, noteA->dots) - calculateDuration(noteB->duration, noteB->dots);
}

// Function to compare two rests based on their duration
int compareRestDuration(const void *a, const void *b) {
    Rest *restA = (Rest *)a;
    Rest *restB = (Rest *)b;
    return calculateDuration(restA->duration, restA->dots) - calculateDuration(restB->duration, restB->dots);
}

// Function to simplify a note sequence
void simplifyNoteSequence(Note *notes, int noteCount, char *output, int *outputLength) {
    // Sort notes by duration
    qsort(notes, noteCount, sizeof(Note), compareNoteDuration);

    // Initialize output string
    *outputLength = 0;

    // Iterate through sorted notes
    int i = 0;
    while (i < noteCount) {
        // Get the current note and its duration
        Note currentNote = notes[i];
        int currentDuration = calculateDuration(currentNote.duration, currentNote.dots);

        // Find the longest sequence of notes with the same duration
        int j = i + 1;
        while (j < noteCount && calculateDuration(notes[j].duration, notes[j].dots) == currentDuration) {
            j++;
        }

        // Append the note to the output string
        output[*outputLength] = currentNote.note;
        (*outputLength)++;
        if (currentNote.duration != 1) {
            output[*outputLength] = (char)(currentNote.duration + '0');
            (*outputLength)++;
        }
        if (currentNote.dots > 0) {
            for (int k = 0; k < currentNote.dots; k++) {
                output[*outputLength] = '.';
                (*outputLength)++;
            }
        }

        // Update i to skip the processed notes
        i = j;
    }
}

// Function to simplify a rest sequence
void simplifyRestSequence(Rest *rests, int restCount, char *output, int *outputLength) {
    // Sort rests by duration
    qsort(rests, restCount, sizeof(Rest), compareRestDuration);

    // Initialize output string
    *outputLength = 0;

    // Iterate through sorted rests
    int i = 0;
    while (i < restCount) {
        // Get the current rest and its duration
        Rest currentRest = rests[i];
        int currentDuration = calculateDuration(currentRest.duration, currentRest.dots);

        // Find the longest sequence of rests with the same duration
        int j = i + 1;
        while (j < restCount && calculateDuration(rests[j].duration, rests[j].dots) == currentDuration) {
            j++;
        }

        // Append the rest to the output string
        output[*outputLength] = 'R';
        (*outputLength)++;
        if (currentRest.duration != 1) {
            output[*outputLength] = (char)(currentRest.duration + '0');
            (*outputLength)++;
        }
        if (currentRest.dots > 0) {
            for (int k = 0; k < currentRest.dots; k++) {
                output[*outputLength] = '.';
                (*outputLength)++;
            }
        }

        // Update i to skip the processed rests
        i = j;
    }
}

int main() {
    char input[100001];
    int caseNum = 1;

    while (1) {
        // Get the input MML sequence
        fgets(input, 100001, stdin);

        // Check for end of input
        if (input[0] == '*') {
            break;
        }

        // Remove trailing newline character
        input[strcspn(input, "\n")] = 0;

        // Parse the MML sequence
        int noteCount = 0;
        Note notes[100000];
        int restCount = 0;
        Rest rests[100000];
        int octave = 4;
        int defaultDuration = 4;
        int volume = 100;
        int i = 0;
        while (input[i] != '\0') {
            // Handle notes
            if (input[i] >= 'C' && input[i] <= 'B') {
                Note note;
                note.note = input[i];
                note.octave = octave;
                note.duration = 4; // Default duration
                note.dots = 0;

                // Handle sharp and flat notes
                if (input[i + 1] == '+' || input[i + 1] == '-') {
                    note.note = input[i + 1];
                    i++;
                }

                // Handle duration specifier
                if (input[i + 1] >= '1' && input[i + 1] <= '9') {
                    note.duration = input[i + 1] - '0';
                    i++;
                    // Handle dots
                    while (input[i + 1] == '.') {
                        note.dots++;
                        i++;
                    }
                }

                // Add the note to the notes array
                notes[noteCount++] = note;
            }

            // Handle rests
            else if (input[i] == 'R') {
                Rest rest;
                rest.duration = 4; // Default duration
                rest.dots = 0;

                // Handle duration specifier
                if (input[i + 1] >= '1' && input[i + 1] <= '9') {
                    rest.duration = input[i + 1] - '0';
                    i++;
                    // Handle dots
                    while (input[i + 1] == '.') {
                        rest.dots++;
                        i++;
                    }
                }

                // Add the rest to the rests array
                rests[restCount++] = rest;
            }

            // Handle octave commands
            else if (input[i] == 'O') {
                if (input[i + 1] >= '1' && input[i + 1] <= '8') {
                    octave = input[i + 1] - '0';
                    i += 2;
                } else if (input[i + 1] == '<') {
                    octave--;
                    i += 2;
                } else if (input[i + 1] == '>') {
                    octave++;
                    i += 2;
                }
            }

            // Handle default duration command
            else if (input[i] == 'L') {
                if (input[i + 1] >= '1' && input[i + 1] <= '9') {
                    defaultDuration = input[i + 1] - '0';
                    i += 2;
                }
            }

            // Handle volume command
            else if (input[i] == 'V') {
                if (input[i + 1] >= '1' && input[i + 1] <= '9') {
                    volume = input[i + 1] - '0';
                    if (input[i + 2] >= '0' && input[i + 2] <= '9') {
                        volume = (volume * 10) + (input[i + 2] - '0');
                        i += 3;
                    } else {
                        i += 2;
                    }
                }
            }

            // Skip invalid characters
            else {
                i++;
            }
        }

        // Simplify note sequence
        char simplifiedNotes[100000];
        int simplifiedNotesLength = 0;
        simplifyNoteSequence(notes, noteCount, simplifiedNotes, &simplifiedNotesLength);

        // Simplify rest sequence
        char simplifiedRests[100000];
        int simplifiedRestsLength = 0;
        simplifyRestSequence(rests, restCount, simplifiedRests, &simplifiedRestsLength);

        // Construct the shortest MML sequence
        char output[100000];
        int outputLength = 0;
        if (simplifiedNotesLength > 0) {
            strcpy(output, simplifiedNotes);
            outputLength = simplifiedNotesLength;
        }
        if (simplifiedRestsLength > 0) {
            if (outputLength > 0) {
                output[outputLength] = ' ';
                outputLength++;
            }
            strcpy(output + outputLength, simplifiedRests);
            outputLength += simplifiedRestsLength;
        }

        // Print the shortest MML sequence
        printf("Case %d: ", caseNum++);
        if (outputLength > 0) {
            printf("%s", output);
        }
        printf("\n");
    }

    return 0;
}