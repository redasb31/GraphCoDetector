#include <stdio.h>
#include <string.h>

#define BUF_SIZE 102
int main(void) {
  char line[BUF_SIZE];
  FILE *fp;
  fp = stdin;
  if(!fgets(line, BUF_SIZE, fp)) return 0;
  size_t len = strlen(line);
  if(line[len-1] == '\n') {
    len--;
  }
  printf("%c%d%c\n", line[0], (int)len, line[len-1]);

  return 0;
}