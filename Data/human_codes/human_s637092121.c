/*
  AOJ 2022
 */
#include <stdio.h>
#include <string.h>

int N;
int num[11];
int frag[11];
int ordr[11];
int prev_ordr[11];
char words[11][11];
char result[101];
char result_partial[11][101];
char shortest[101];

void reverse(int* from ,int *to)
{
  int i;

  for(i=1;i<=N;i++)
    to[i]=from[N+1-i];
}

extern void strcat_erase_common(char *,char *);
void update_shortest(char * r)
{
  if(shortest[0]=='\0' || (strlen(shortest)>strlen(r))
     || ((strlen(shortest)==strlen(r)) && 0<strcmp(shortest,r)))
    {
      strcpy(shortest,r);
    }
}
void strcat_order(int * order)
{
  int i,from;
#ifdef DEBUG
  for(i=1;i<=N;i++)
    printf("%d:",order[i]);
  printf("\n");
#endif
  for(i=1;i<=N;i++)
    if(order[i] != prev_ordr[i]) 
      break;

    from=i-1;
#ifdef DEBUG
    printf("from:%d\n",from);
#endif


  if(from==0)
    {
      memset(&result[0],'\0',11);
    }
  else
    {
      memset(&result[0],'\0',101);
      strcpy(&result[0],&result_partial[from][0]);
    }
  //printf("p:%s\n",&result[0]);
  for(i=from+1;i<=N;i++)
    {
      strcat_erase_common(result,&words[order[i]][0]);
      //printf("%s:",&words[order[i]][0]);
      if(i<N-1)
	strcpy(&result_partial[i][0],result);
    }
  memcpy(prev_ordr,order,11*sizeof(int));
}

void strcat_erase_common(char * buf,char *add)
{
  int i,len;

  if(strstr(buf,add))
    return;

  len=strlen(buf);
  for(i=strlen(add)-1;i>0;i--)
    if(0==strncmp(buf+len-i,add,i))
      {
      strcat(buf,add+i);
      return;
      }
  strcat(buf,add);
  return;
}

void fx(int n,int k)
{
  int i,f,j;

  if(n==1)
    {
      strcpy(shortest,&words[1][0]);
      return;
    }

  for(i=0;i<n;++i)
    {
      f=frag[i];
      if(f == 0)
	{
	  frag[i]=1;
	  num[k] = i+1;
	  if(k==1)
	    {
	      reverse(num,ordr);
	      strcat_order(ordr);
#ifdef DEBUG2
	      printf("%s\n",result);
#endif
	      update_shortest(result);
	    }
	  else
	    {
	      fx(n,k-1);
	    }
	  frag[i] = 0;
	}
    }
}

int main()
{
int i,k;


 while(EOF!=scanf("%d",&N) && N)
   {
     memset(num,0,N*sizeof(int));
     memset(frag,0,N*sizeof(int));

     for(i=1;i<=N;i++)
       scanf("%s ",&(words[i][0]));
#ifdef DEBUG2
  for(i=1;i<=N;i++)
    printf("%s:",&words[i][0]);
  printf("\n");
#endif
     memset(shortest,'\0',100);
     memset((char *)result_partial,'\0',10*101);
     memset(prev_ordr,0,sizeof(int)*10);

     fx(N,N);
     printf("%s\n",shortest);
   }
 return(0);
}