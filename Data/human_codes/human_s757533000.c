#include<stdio.h>
 
int main()
{
  long long int a,b,c,d,n;
  scanf("%lld %lld %lld %lld %lld",&a, &b, &c, &d, &n);
  
  if((n>=a && n<=b) && (n>=c && n<=d)){
    printf("Yes");
  }
   
   else{
     printf("No");
   }
  return 0;
}