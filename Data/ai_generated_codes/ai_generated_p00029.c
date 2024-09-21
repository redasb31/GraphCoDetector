#include <stdio.h>
#include <string.h>

// Function to count the frequency of each word in the text
void countWordFrequency(char text[], int wordFrequency[], char words[][32]) {
  int i, j, k, wordCount = 0;
  char currentWord[32] = "";

  // Iterate through the text to count words
  for (i = 0; text[i] != '\0'; i++) {
    // If character is a letter, add it to the current word
    if (isalpha(text[i])) {
      currentWord[j++] = text[i];
    } else {
      // If character is a space, it means end of a word
      currentWord[j] = '\0';
      // Check if the word already exists in the words array
      for (k = 0; k < wordCount; k++) {
        if (strcmp(currentWord, words[k]) == 0) {
          // Increment the frequency of the existing word
          wordFrequency[k]++;
          break;
        }
      }

      // If word is new, add it to the words array
      if (k == wordCount) {
        strcpy(words[wordCount], currentWord);
        wordFrequency[wordCount]++;
        wordCount++;
      }

      // Reset current word for the next word
      j = 0;
    }
  }

  // Handle the last word in the text
  currentWord[j] = '\0';
  for (k = 0; k < wordCount; k++) {
    if (strcmp(currentWord, words[k]) == 0) {
      wordFrequency[k]++;
      break;
    }
  }
  if (k == wordCount) {
    strcpy(words[wordCount], currentWord);
    wordFrequency[wordCount]++;
  }
}

int main() {
  char text[1000];
  char words[100][32];
  int wordFrequency[100] = {0};

  // Read the text from the user
  printf("Enter the text: ");
  fgets(text, 1000, stdin);

  // Remove the newline character from the input
  text[strcspn(text, "\n")] = '\0';

  // Count the frequency of each word in the text
  countWordFrequency(text, wordFrequency, words);

  // Find the most frequent word
  int maxFrequency = 0, maxFrequencyIndex = 0;
  for (int i = 0; i < 100; i++) {
    if (wordFrequency[i] > maxFrequency) {
      maxFrequency = wordFrequency[i];
      maxFrequencyIndex = i;
    }
  }

  // Find the word with maximum letters
  int maxLetters = 0, maxLettersIndex = 0;
  for (int i = 0; i < 100; i++) {
    if (strlen(words[i]) > maxLetters) {
      maxLetters = strlen(words[i]);
      maxLettersIndex = i;
    }
  }

  // Print the most frequent word and the word with maximum letters
  printf("%s %s\n", words[maxFrequencyIndex], words[maxLettersIndex]);

  return 0;
}