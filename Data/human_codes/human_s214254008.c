#include<stdio.h>
#include<stdlib.h>
int calc(int x, int y, int z)
{
  switch (z){
  case 0: return (x + y);
  case 1: return (x - y);
  case 2: return (x * y);
  }
}
int hantei(int a, int b, int c, int d){
  char en[3]={'+','-','*'};
    for(i=0;i<3;i++){
      for(j=0;j<3;j++){
	int(k=0;k<3;k++){
	  if (calc(calc(a, b, i), calc(c, d, j), k) == 10){
	    return printf("(%d%c%d)%c(%d%c%d)\n", a, en[i], b, en[k], c, en[j], d);
	  }
	  if (calc(calc(calc(a, b, i), c, j), d, k) == 10){
	      return printf("((%d%c%d)%c%d)%c%d\n", a, en[i], b, en[j], c, en[k], d);
	  }
	}
      }
    }
    return 0;
}
int main(void){
  int a, b, c, d;
  while (scanf("%d %d %d %d", &a, &b, &c, &d)!=EOF){
    if(check(a, b, c, d)) continue;//??¨??????????????´?????????
    else if(check(a, b, d, c)) continue;
    else if(check(a, c, b, d)) continue;
    else if(check(a, c, d, b)) continue;
    else if(check(a, d, b, c)) continue;
    else if(check(a, d, c, b)) continue;
    else if(check(b, a, d, c)) continue;
    else if(check(b, a, c, d)) continue;
    else if(check(b, c, a, d)) continue;
    else if(check(b, c, d, a)) continue;
    else if(check(b, d, a, c)) continue;
    else if(check(b, d, c, a)) continue;
    else if(check(c, a, b, d)) continue;
    else if(check(c, a, d, b)) continue;
    else if(check(c, b, a, d)) continue;
    else if(check(c, b, d, a)) continue;
    else if(check(c, d, a, b)) continue;
    else if(check(c, d, b, a)) continue;
    else if(check(d, a, b, c)) continue;
    else if(check(d, a, c, b)) continue;
    else if(check(d, b, a, c)) continue;
    else if(check(d, b, c, a)) continue;
    else if(check(d, c, a, b)) continue;
    else if(check(d, c, b, a)) continue;
    printf("0\n");
  }
  return 0;
}
 