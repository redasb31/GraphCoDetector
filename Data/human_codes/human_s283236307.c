#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
int i;
int c;

scanf("%d",&c);

for(i=0;i<=c;i++){
   if(i%3==0){
   printf(" %d",i);}
   else{
   if(i%10==3){
   printf(" %d",i);}}
}
return 0;
}
