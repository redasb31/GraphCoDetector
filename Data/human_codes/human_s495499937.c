#include<stdio.h>
int a, b, c;
int main(){
  scanf("%d%d%d", &a, &b, &c);
  if(a>c){a^=c; c^=a; a^=c;}
  if(b>c){b^=c; c^=b; b^=c;}
  if(a==5 && b==5 && c==7){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
}
