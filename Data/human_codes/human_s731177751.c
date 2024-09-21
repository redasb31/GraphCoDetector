#include <stdlib.h>
#include <stdio.h>
int ans[20000];
check(int n)
{
  int x;
  int count=0;
  if(ans[n-1]==0)
    check(n-1);
  for(x=1;x<n;x++)
    if(n%x!=0)
      count++;
  ans[n]=count+ans[n-1]+1;
  //  printf("ans[%d]=%d\n",n,ans[n]);
}
main()
{
  int t,n;
  ans[0]=-1;
  ans[1]=2;
  ans[2]=3;
  ans[3]=5;
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d",&n);
      if(ans[n]==0)     
	check(n);
      printf("%d\n",ans[n]); 
    }
  exit(0);
}