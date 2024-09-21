#include<stdio.h>

int main(){
  int a = 0, b = 0, c = 0, x = 0, y = 0;
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
  int s = 0;
  int z = 0;

  if (x >= y){
    if(a + b <= 2*c){
      s = 1;
    }else if(2*c > a){
      s = 2;
    }else if(a >= 2*c){
      s = 3;
    }
  }else{
    if(a + b <= 2*c){
      s = 1;
    }else if(2*c > b){
      s = 4;
    }else if(b >= 2*c){
      s = 5;
    }
  }

  switch(s){
    case 1:
      z = a*x + b*y;
      break;
    case 2:
      z = a*(x-y) + 2*c*y;
      break;
    case 3:
      z = 2*c*x;
      break;
    case 4:
      z = b*(y-x) + 2*c*x;
      break;
    case 5:
      z = 2*c*y;
      break;
  }
  //printf("case %d ", s);
  printf("%d", z);

  return 0;
}
