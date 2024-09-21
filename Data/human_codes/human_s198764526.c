#include<stdio.h>
int main(void){
int N,f,a,sum=0;
scanf("%d",&N);
a=N;
while(a>0){
f=a%10;
sum=sum+f;
a=a/10;}
if(N%sum==0)
printf("N is Harshard Number ");
else
printf(" NO ");
return 0;
}
