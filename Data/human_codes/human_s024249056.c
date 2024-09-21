/*
  AOJ 2022
  Title:Princess, a Cryptanalyst
  @kankichi573
  14/6/19 TLE
*/
#include <stdio.h>
#include <string.h>

#define min(x,y) (((x)<(y))?(x):(y))
int n;
int min_;
char words[10][11];
char min_str[101];

void shortest_connect(char *in1,char *in2,char *ret)
{
  int i,len;

  if(strstr(in1,in2))
    {
      strcpy(ret,in1);
      return;
    }
  if(strstr(in2,in1))
    {
      strcpy(ret,in2);
      return;
    }
  len=strlen(in1);
  
  for(i=len-1;i>0;i--)
    if(0==strncmp(in1+len-i,in2,i))
      {
	strcpy(ret,in1);
	strcat(ret,in2+i);
	return;
      }
  
  if(in1[len]==in2[0])
    {
      strncpy(ret,in1,len);
      strcat(ret,in2+1);
      return;
    }
  strcpy(ret,in1);
  strcat(ret,in2);

}
void solve(int use,int no,char *acc)
{
  int i,len,mask;
  char ret[100];
#ifdef DEBUG
  printf("s> %d %s\n",use,acc);
#endif
  if(no==0)
    {
	if((len=strlen(acc))<min_)
	  {
	      min_=len;
	      strcpy(min_str,acc);
	      return;
	  }
    }
   else
    for(i=0;i<n;i++)
      {
	mask = 1<<i;
	if(use & mask)
	  {
	    shortest_connect(acc,&words[i][0],ret);
	    solve(use^mask,no-1,ret);
	  }
      }
}

main()
{
  int i;
  int use;
  char acc[100];


  while(scanf("%d",&n) && n)
    {
      for(i=0;i<n;i++)
	scanf("%s",&words[i][0]);
      use= (1<<n)-1;
      min_=101;
      acc[0]='\0';
      solve(use,n,acc);
      printf("%s\n",min_str);
    }

  return(0);
  
}