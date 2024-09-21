/*
  AOJ #2816
  title:Alphabet Block
  @kankichi573
 */
#include <stdio.h>
#include <string.h>

int alpha[26];
char s[1001];

int main()
{
  char *p;
  int i,ret;

  memset(alpha,0,sizeof(alpha));
  scanf("%s",s);
  for(p=s;*p;p++)
    alpha[*p-'a']++;
  for(i=ret=0;i<26;i++)
    ret+=(alpha[i]%2);

  printf("%d\n",ret/2);
  return(0);
}