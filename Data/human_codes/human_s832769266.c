#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int gcd(int x, int y){
  return y ? gcd(y, x%y) : x;
}

int print(int x, int y){
  int g = gcd(x, y);
  printf("%d/%d\n", x/g, y/g);
}

int main(){
  char in[10], all[10], sub[10];
  scanf("%s", in);
  int o, p, l, r, d, i, all_i = 0;
  p = -1;

  for ( i = 0; i < strlen(in); i++ ){
    if ( in[i] == '.' ){
      o = i;
    } else if ( in[i] == '(' ) {
      p = i;
      strncpy(sub, all, all_i);
      sub[all_i] = '\0';
    } else if ( in[i] == ')' ) {
    } else {
      all[all_i++] = in[i];
    }
  }
  all[all_i] = '\0';

  d = strlen(in) - o - 1;
  l = p - o - 1;
  if ( p == -1 ){
    print(atoi(all), pow(10, d));
  }else {
    d -= 2; // for ()
    print(atoi(all) - atoi(sub), pow(10, d) - pow(10, l) );
  }
  return 0;
}



