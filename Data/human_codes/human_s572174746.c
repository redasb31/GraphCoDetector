/*
  AOJ 2800
  Title:Mod!Mod!
  @kankichi573
*/
#include <stdio.h>
#define myabs(a,b)  ((a)>(b))?((a)-(b)):((b)-(a))

main()
{
  int N,i,uma,ret,count[3],diff;
  
  count[0]=count[1]=count[2]=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    { scanf("%d",&uma);
      count[uma % 3]++;
    }

  if(count[1]==0 && count[2]==0)
    ret=1;
  else 
    {
      diff=myabs(count[1],count[2]);
      if(diff<4)
	ret = N;
      else
	ret = N - (diff-3);
    }
  printf("%d\n",ret);
  
  return(0);
}