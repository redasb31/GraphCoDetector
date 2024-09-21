#include <stdio.h>
#include <string.h>
main()
{
  int i,j,k;
  char *a = " ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *b[] = {
    "101","000000","000011","10010001","010001","000001","100101",
    "10011010","0101","0001","110","01001","10011011","010000","0111",
    "10011000","0110","00100","10011001","10011110","00101","111",
    "10011111","1000","00110","00111","10011100","10011101","000010",
    "10010010","10010011","10010000"
  };
  char *c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
  char d[4096];
  char e[4096];
  d[0] = '\0';
  while(gets(e)) {
    strcat(d,e);
    strcat(d," ");
  }
  d[strlen(d)] = '\0';
  e[0] = '\0';
  i = 0;
  while(d[i] != '\0') strcat(e,b[strchr(a,d[i++]) - a]);
  i = 5 - strlen(e) % 5;
  while(i--) strcat(e,"0");
  i = 0;
  while(e[i] != '\0') {
    j = 0;
    k = 4;
    do {
      j += (e[i++] - '0') << k;
    } while(k--);
    putc(c[j],stdout);
  }
  putc('\n',stdout);
  return 0;
}