/*
  AOJ 1248
  Title:The Balance
  @kankichi573
*/
#include <stdio.h>
#define MAX 99999999

main()
{
  int A,B,D,both,left,ax,flag,i,j,ans_a,ans_b;
  while(scanf("%d%d%d",&A,&B,&D) && (A||B||D))
    {
      for(ax=MAX,flag=i=0;flag==0;i++)
	for(j=0;j<=i;j++)
	  {
	    both=A*j-B*(i-j);
	    left=A*j+B*(i-j);
	    if(left==D||both==D||both==-D)
	      {
		flag=1;
		if(ax>left)
		  {
		    ax=left;
		    ans_a=j;
		    ans_b=i-j;
		  }
	      }
	  }
	  printf("%d %d\n",ans_a,ans_b);
    }
  return(0);
}