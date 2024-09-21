#include<stdio.h>
int n,a,b,i,j,m;
int main(void){
scanf("%d%d%d",&n,&a,&b);
if(a <= b){
i = a;
m = b;
}else{
i = b;
m = a;
}
 // printf("%d,%d",i,m);
if(n-a+b > n){
j = a+b-n;
}else{
  j = 0;

}
  
printf("%d %d\n",i,j);
return 0;
}

