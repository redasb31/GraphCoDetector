#include<stdio.h>
int main(){
  int a,b,c,s=1,i;
  scanf("%d %d %d",&a,&b,&c);
  c-=a*b;
  if(c<0)printf("0\n");
  else{
    c+=--a;//printf("%d %d\n",a,c);
    if(a>c-a)a=c-a;
    for(i=0;i<a;i++){
      s*=c--;
      s/=i+1;
    }
    printf("%d\n",s);
  }
  return 0;
}