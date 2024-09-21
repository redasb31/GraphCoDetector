#include <stdio.h>
#include <math.h>
 
int main(){
  int n,a,b;
  scanf("%d %d %d",&n,&a,&b);
 // int d = a ^ b;
  int num = (int)pow(2,n) - 1;
  int count[n];
  int tmp = 1;
  for(int i = 0; i < n; ++i){//a=~1~,b=~0~ -> 1, a=~0~,b=~1~ => -1, other -> 0
    count[i] = ((a & tmp)/tmp) - ((b & tmp)/tmp);
    tmp *= 2;
  }
  int check = 0;
  for(int i = 0; i < n; ++i) check += (count[i] * count[i]);//異なるbitの個数
  if(check % 2 == 0) printf("NO\n");//p0 -> p[2^n-1]で切り替えは奇数回
  else{
    printf("YES\n%d",a);
    int p = a;
    for(int i = 0; i < n; ++i){//異なるbitの部分を下から1桁ずつa -> b
      if(count[i] == 0) ;
      else if(count[i] == 1){// a=1,b=0 (下にi桁)
        p = p - (int)pow(2,i);
        printf(" %d",p);
      }else if(count[i] == -1){// a=0,b=1
        p = p + (int)pow(2,i);
        printf(" %d",p);
      }
    }
    for(int i = 0; i < num - check; ++i){//+-1を繰り返す
      if(p % 2 == 0){
        p += 1;
        printf(" %d",p);
      }else if(p % 2 == 1){
        p -= 1;
        printf(" %d",p);
      }
    }
  }
  printf("\n");
  return 0;
}