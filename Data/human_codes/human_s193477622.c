#include <stdio.h>

#define STRMAX 11

int main(void)
{
  int i;

  int index;
  char c;
  char output[STRMAX];

  for (i = 0; i < STRMAX; i++)output[i] = '\0';

  index = 0;
  while (1) {
    scanf("%c", &c);
    if (c == '0' || c == '1') {
      output[index] = c;
      index++;
    } else if(c=='B'){
      if (index > 0) {
        index--;
        output[index] = '\0';
      }
    } else {
      break;
    }
  }
  printf("%s\n", output);
  return(0);
}