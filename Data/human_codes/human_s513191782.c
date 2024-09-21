#include <stdio.h>
#include <string.h>

int main(){
  int p, q, n, i, j, res[80], mod[80], place;
  while(scanf("%d%d", &p, &q) != EOF){
    memset(mod, 0, sizeof(mod));
    i = 0;
    p %= q;
    mod[i++] = p;
    p *= 10;

    place = -1;
    while(p){
      putchar((p / q) + '0');
      p %= q;
      p *= 10;
      for(j = 0;mod[j]; ++j){
	if(p == mod[j]){
	  place = j;
	  break;
	}
      } 
      if(place >= 0) break;
      mod[i++] = p;
    }
    puts("");
    if(p){
      i -= place;
      while(place--) putchar(' ');
      while(i--) putchar('^');
      puts("");
    }
  }
  return 0;
}