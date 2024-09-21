/*
  AOJ #2831
  title:
  @kankichi573
 */
#include <stdio.h>
#include <string.h>

int n;
char c;

int main()
{
  int i,err,ans;
  
  scanf("%d",&n);
  for(i=err=0;i<n;i++)
    {
      scanf("%c",&c);
      if(c=='x')
	if(err==1)
	  {
	    ans = i-1;
	    goto END;
	  }
	else
	  err=1;
      else
	err=0;
    }
  
  ans = n;
 END:
  printf("%d\n",ans);
  return(0);
}


