#include<stdio.h>
#include<string.h>

int main(){
  int i, len, h0, h1, h2, h3, in;
  char str[20];
  
  h0 = h1 = h2 = h3 = 0;

  scanf("%s", str);

  len = strlen(str);

  if(len >= 6) h0 = 1;

  for(i=0; i<len; i++){
    in = str[i];
    if(in >= 48 && in <=57) h1 = 1;
    else if(in <= 90 && in >=65) h2 = 1;
    else if(in >= 97 && in <=122) h3 = 1;
  }
  
  if(h0==1 && h1==1 && h2==1 && h3==1) printf("VALID\n");
  else printf("INVALID\n");

  return 0;
}