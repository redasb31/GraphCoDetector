#include <stdio.h>
#include <math.h>
int main()
{
  double s[1001];
  double temp,av,ss,sss;
  int i,n;
 
  while(1){
    scanf("%d",&n);
    if(!n) break;
  for(i=1; i<=n; i++){
  if(i!=1) putchar(' ');
   scanf("%lf",&s[i]);
    temp += s[i];
  }
   av = temp / n;
   for(i=1; i<=n; i++){
   ss  += (s[i]-av)*(s[i]-av);
   }
   sss =sqrt(ss);
   printf("%f\n",sss/n);
}
return 0;
}