/*
  AOJ 2615
  Title:A+B
  @kankichi573
*/
#include <stdio.h>
#include <string.h>
char A[300001],B[300001];
char Ar[300001],Br[300001];

void invert_bit(char array[],int pos)
{
  array[pos] = (array[pos]=='0')?'1':'0';
}
int query(char array1[],char array2[])
{
  int i,ret,zc;

  zc=ret=0;
  for(i=0;array1[i];i++)
    {
      if(array2[i]=='1')
	{
	  if(zc>0)
	    {
	      ret += zc;
	      if(array1[i]=='1')
		ret++;
	    }
	  else
	    ret ++;
	  zc=0;
	}
      else if(array1[i]=='0' && array2[i]=='0')
	zc++;
      else if(array1[i]=='1')
	ret++;
      //printf("%d %d [%d]|",i,ret,zc);
    }
  return(ret);
}
void dump()
{
  printf("%s\n",Ar);
  printf("%s\n\n",Br);
}

main()
{
  char q;
  int N,i,j,ret,bit;
  int len_a,len_b,msb_b;

  scanf("%d %s %s ",&N,&A[0],&B[0]);
  len_a=strlen(A);
  len_b=strlen(B);

  for(i=0,j=len_a-1;i<len_a;i++,j--)
    Ar[i]=A[j];
  for(i=0,j=len_b-1;i<len_b;i++,j--)
    Br[i]=B[j];
  for(i=0;i<len_b;i++)
    if(Br[i]=='0')
      Br[i]='1';
    else
      {
	Br[i]='0';
	break;
      }
      
  //dump();

  for(i=0;i<N;i++)
    {
      scanf("%c ",&q);
      if(q=='Q')
	printf("%d\n",query(Ar,Br));
      else if(q=='A')
	{
	  scanf("%d ",&bit);
	  //printf("A [%d]\n",bit);
	  invert_bit(Ar,bit);
	}
      else if(q=='B')
	{
	  scanf("%d ",&bit);
	  //printf("B [%d]\n",bit);
	  invert_bit(Br,bit);
	}
      //dump();
    }
  return(0);
}