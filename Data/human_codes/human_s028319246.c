/*
AOJ #2727
title:M and A
@kankichi573
*/

#include <stdio.h>
#include <string.h>

int strcmp_wild(char *s1,char *s2)
{
  //printf("s1=%s|s2=%s\n",s1,s2);

  if(!*s1 && !*s2)
    return (1);
  else if(*s1=='*' && !*(s1+1) && !*s2)
    return (1);
  else if(!*s1 || !*s2)
    return (0);
  else if(*s1 == '*')
    return( strcmp_wild(s1+1,s2) || strcmp_wild(s1,s2+1));
  else if(*s1 == *s2)
    return( strcmp_wild(s1+1,s2+1));
  else
    return(0);
}

char s[1001],t[1001];

int solve(char *s,char *t)
{

  int i,len = strlen(s),r1,r2;
  char buf[2][1001];

  memset(buf,'*',sizeof(buf));
  for(i=0;i<len;i++)
    if((i % 2)==0)
      buf[0][i+1] = s[i];
    else
      buf[1][i] = s[i];
  if((len % 2)==0)
    len++;
  buf[0][len]=buf[1][len]='\0';


  //printf("%s\n",&buf[0][0]);
  //printf("%s\n",&buf[1][0]);

  r1=strcmp_wild(&buf[0][0],t) ;
  r2=strcmp_wild(&buf[1][0],t);
 
  //printf("r1,r2=%d %d\n",r1,r2);
 
  return(r1||r2);
}


int main()
{
  int ret;
  
  scanf("%s",s);
  scanf("%s",t);
  ret=solve(s,t);
  //ret=strcmp_wild(s,t);
  printf("%s\n",ret?"yes":"no");
  return(0);
}