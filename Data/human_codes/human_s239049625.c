#include <stdio.h>

int main(){
   long a;
   int i,n,g;

   scanf("%d",&n);
   for (i=0;i<n;i++) {
      scanf("%ld\n",&a);
      if (a%2==0) g++;
   }
   if (n==g) puts("second");
   else      puts("first");
   return 0;
}
