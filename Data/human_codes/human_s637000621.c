#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
  unsigned long n,i,i2,now,r,mod;

  scanf("%ld", &n);

  i = n % 2;
  now = 1;
  r=0;
  while(i<n)
  {
  //printf("i: %ld, now: %ld, r: %ld\n", i, now, r);
    i += 2;
    i2 = i;
    while ((i2 % 10) == 0)
    {
      r++;
      i2 /= 10;
    }
    i2 = i2 % 1000;
    now = now % 1000;

    if (i2 != 0) now *= i2;

   // printf("i: %ld, now: %ld, r: %ld\n", i, now, r);
   // printf("now  per 10: %d\n", now % 10);
    while ((now % 10) == 0)
    {
    //printf("now: %ld\n",now);
      r++;
      now /= 10;
    }
  }
  printf("%ld\n",r);

  return 0;
}
