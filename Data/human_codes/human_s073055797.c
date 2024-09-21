#include<stdio.h>
#include<string.h>
#define N 200
#define T 100
int main()
{
  int t,n,x=0,k=0,i=0;
  long long int a[N];
  char s[N];
  scanf("%d",&t);
  while(scanf("%d",&n)!=EOF))
  {
    for(i=0;i<n;i++)
    {
      scanf("%lld ",&a[i]);
      if(a[i]%2==0)
      {
        a[i]=0;
      }
      else
      {
        a[i]=1;
      }
    }
    for(i=0;i<n;i++)
    {
      scanf("%c",&s[i]);
    }
    for(i=0;i<n;i++)
    {
      if(s[i]=='1')
      {
        x=1;
        k=x XOR a[i];
      }
      else 
      {
        k=x XOR a[i];
      }
    }
    printf("%d",k);
  }
  return 0;
}

  
    
  
  