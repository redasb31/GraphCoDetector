#include <stdio.h>

// Structure to represent a skill
typedef struct {
  int max_level;
  int importance;
  int prerequisite;
  int min_prereq_level;
} Skill;

// Function to calculate the programming competence
int calculate_competence(Skill skills[], int n, int levels[]) {
  int competence = 0;
  for (int i = 0; i < n; i++) {
    competence += levels[i] * skills[i].importance;
  }
  return competence;
}

// Function to find the maximum competence achievable within the budget
int find_max_competence(Skill skills[], int n, int budget) {
  int max_competence = 0;
  // Initialize levels of all skills to 0
  int levels[n] = {0};

  // Iterate through the skills in order of prerequisites
  for (int i = 0; i < n; i++) {
    // If the skill has a prerequisite, check if the prerequisite level is met
    if (skills[i].prerequisite != 0 && levels[skills[i].prerequisite - 1] < skills[i].min_prereq_level) {
      continue;
    }
    // Iterate through possible levels for the skill
    for (int level = 1; level <= skills[i].max_level; level++) {
      // Calculate the cost of upgrading the skill to the current level
      int cost = level - levels[i];
      // If the cost exceeds the budget, break
      if (budget - cost < 0) {
        break;
      }
      // Update the level and budget
      levels[i] = level;
      budget -= cost;
      // Calculate the current competence
      int competence = calculate_competence(skills, n, levels);
      // Update the maximum competence if necessary
      if (competence > max_competence) {
        max_competence = competence;
      }
    }
  }
  return max_competence;
}

int main() {
  int n, k;
  while (scanf("%d %d", &n, &k) != EOF && (n != 0 || k != 0)) {
    Skill skills[n];

    // Read skill information
    for (int i = 0; i < n; i++) {
      scanf("%d", &skills[i].max_level);
    }
    for (int i = 0; i < n; i++) {
      scanf("%d", &skills[i].importance);
    }
    for (int i = 1; i < n; i++) {
      scanf("%d", &skills[i].prerequisite);
    }
    for (int i = 1; i < n; i++) {
      scanf("%d", &skills[i].min_prereq_level);
    }

    // Find the maximum competence achievable
    int max_competence = find_max_competence(skills, n, k);

    // Print the maximum competence
    printf("%d\n", max_competence);
  }
  return 0;
}