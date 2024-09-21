#include <stdio.h>
#include <string.h>

// Function to calculate the number of distinct configurations
// for a given sub-train length
int count_configurations(int sub_train_length) {
  // If the sub-train length is 1, there's only one configuration
  if (sub_train_length == 1) {
    return 1;
  }
  // Otherwise, the number of configurations is twice the number
  // of configurations for a sub-train length one less
  return 2 * count_configurations(sub_train_length - 1);
}

int main() {
  int num_datasets;
  char train_config[73];

  // Read the number of datasets
  scanf("%d", &num_datasets);

  // Process each dataset
  for (int i = 0; i < num_datasets; i++) {
    // Read the train configuration
    scanf("%s", train_config);

    // Calculate the length of the train
    int train_length = strlen(train_config);

    // Initialize the count of distinct configurations to 0
    int count = 0;

    // Iterate over all possible splitting positions
    for (int j = 1; j < train_length; j++) {
      // Calculate the number of configurations for the two sub-trains
      int sub_train1_count = count_configurations(j);
      int sub_train2_count = count_configurations(train_length - j);

      // Add the product of the sub-train configurations to the total count
      count += sub_train1_count * sub_train2_count;
    }

    // Print the count of distinct configurations
    printf("%d\n", count);
  }

  return 0;
}