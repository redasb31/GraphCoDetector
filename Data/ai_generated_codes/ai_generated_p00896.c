#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 20
#define MAX_WORD_LEN 20
#define MAX_SEQUENCE_LEN 80

// Function to check if two words are compatible with a given substitution rule
int is_compatible(char *word1, char *word2, char rule[][2], int rule_size) {
  int i;
  for (i = 0; i < rule_size; i++) {
    if (strchr(word1, rule[i][0]) && strchr(word2, rule[i][1]) ||
        strchr(word1, rule[i][1]) && strchr(word2, rule[i][0])) {
      return 1;
    }
  }
  return 0;
}

// Function to decipher a word using a substitution rule
void decipher_word(char *ciphertext_word, char *plaintext_word, char rule[][2], int rule_size) {
  int i;
  for (i = 0; ciphertext_word[i] != '\0'; i++) {
    int found = 0;
    for (int j = 0; j < rule_size; j++) {
      if (ciphertext_word[i] == rule[j][0]) {
        plaintext_word[i] = rule[j][1];
        found = 1;
        break;
      } else if (ciphertext_word[i] == rule[j][1]) {
        plaintext_word[i] = rule[j][0];
        found = 1;
        break;
      }
    }
    if (!found) {
      plaintext_word[i] = ciphertext_word[i];
    }
  }
}

// Function to find the plaintext message from a ciphertext message and a list of candidate words
int decipher(char *ciphertext, char *words[], int num_words, char *plaintext) {
  int i, j, k;
  int rule_size = 0;
  char rule[MAX_WORDS][2];

  // Try all possible combinations of substitution rules
  for (i = 0; i < num_words; i++) {
    for (j = i + 1; j < num_words; j++) {
      // Check if the two words are compatible
      if (is_compatible(words[i], words[j], rule, rule_size)) {
        continue;
      }
      // Add the new substitution pair to the rule
      rule[rule_size][0] = words[i][0];
      rule[rule_size][1] = words[j][0];
      rule_size++;

      // Decipher the ciphertext using the current rule
      char *ciphertext_word = strtok(ciphertext, " ");
      char *plaintext_word = malloc(MAX_WORD_LEN + 1);
      int word_count = 0;
      while (ciphertext_word != NULL) {
        decipher_word(ciphertext_word, plaintext_word, rule, rule_size);
        // Check if the deciphered word is in the list of candidate words
        int found = 0;
        for (k = 0; k < num_words; k++) {
          if (strcmp(plaintext_word, words[k]) == 0) {
            found = 1;
            break;
          }
        }
        if (found) {
          // Append the deciphered word to the plaintext message
          if (word_count > 0) {
            strcat(plaintext, " ");
          }
          strcat(plaintext, plaintext_word);
          word_count++;
        } else {
          // If the deciphered word is not in the list, reset the rule
          rule_size = 0;
          break;
        }
        ciphertext_word = strtok(NULL, " ");
      }
      free(plaintext_word);

      // If the entire ciphertext message was deciphered successfully, return 1
      if (word_count > 0) {
        return 1;
      }
    }
  }
  // If no valid substitution rule was found, return 0
  return 0;
}

int main() {
  int num_words;
  char words[MAX_WORDS][MAX_WORD_LEN + 1];
  char ciphertext[MAX_SEQUENCE_LEN + 1];
  char plaintext[MAX_SEQUENCE_LEN + 1];

  while (1) {
    scanf("%d", &num_words);
    if (num_words == 0) {
      break;
    }

    // Read candidate words
    for (int i = 0; i < num_words; i++) {
      scanf("%s", words[i]);
    }

    // Read ciphertext message
    scanf("%s", ciphertext);

    // Initialize plaintext message
    plaintext[0] = '\0';

    // Decipher the ciphertext
    if (decipher(ciphertext, words, num_words, plaintext)) {
      printf("%s.\n", plaintext);
    } else {
      printf("-.");
    }
  }

  return 0;
}