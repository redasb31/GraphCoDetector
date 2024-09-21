#include <stdio.h>
#include <stdlib.h>

// Structure to store program information
typedef struct {
  int start_time;
  int end_time;
  int channel;
} Program;

// Function to compare programs based on their start time
int compare_programs(const void *a, const void *b) {
  Program *program_a = (Program *)a;
  Program *program_b = (Program *)b;
  return program_a->start_time - program_b->start_time;
}

int main() {
  int N, C;
  scanf("%d %d", &N, &C);

  // Array to store all programs
  Program programs[N];
  for (int i = 0; i < N; i++) {
    scanf("%d %d %d", &programs[i].start_time, &programs[i].end_time, &programs[i].channel);
  }

  // Sort programs by their start time
  qsort(programs, N, sizeof(Program), compare_programs);

  // Initialize variables to keep track of recorders
  int num_recorders = 0;
  int *last_recording_time = malloc(C * sizeof(int));
  for (int i = 0; i < C; i++) {
    last_recording_time[i] = 0;
  }

  // Iterate through each program
  for (int i = 0; i < N; i++) {
    // Find the recorder currently recording the channel
    int recorder_index = -1;
    for (int j = 0; j < C; j++) {
      if (programs[i].channel == j && programs[i].start_time >= last_recording_time[j]) {
        recorder_index = j;
        break;
      }
    }

    // If no recorder is found, assign a new recorder
    if (recorder_index == -1) {
      num_recorders++;
      recorder_index = programs[i].channel - 1;
      last_recording_time[recorder_index] = programs[i].end_time;
    } else {
      // Update the last recording time for the recorder
      last_recording_time[recorder_index] = programs[i].end_time;
    }
  }

  // Print the minimum number of recorders
  printf("%d\n", num_recorders);

  free(last_recording_time);
  return 0;
}