#include<stdio.h>
int main(){
char a[17];
int x,y;
while(scanf("%s %d %d",a,&x,&y)!=EOF){
printf("%s %d %d\n",a,x+y,x*200+y*300);
}
return 0;
}