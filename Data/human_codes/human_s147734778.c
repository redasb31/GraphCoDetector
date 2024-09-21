#include<stdio.h>
int main(){
int a,b,c,d;
scanf("%d %d %d %d\n",&a,&b,&c,&d);
a=a*b,c=c+d;
if(a%2==1 && c%2==1){
printf("No\n");
}
else{
printf("Yes\n");
}
return 0;
}
