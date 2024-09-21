#include <stdio.h>
int main(){

  long long a,b;
  scanf("%lld %lld",&a,&b);
  if(b==1) printf("%lld\n",a*(a-1)/2);
  else printf("%lld\n",(a-b+3)*(a-b)/2+b-2);
  return 0;

}