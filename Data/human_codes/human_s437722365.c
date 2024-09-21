#include <stdio.h>
#include <string.h>
#define Max(a, b) ((a) > (b) ? (a) : (b))

int
main(int argc, char *argv[])
{
  char s[51];
  scanf("%s", s);
  int n = strlen(s);
  if(n > 9 || n < 5) printf("NO\n");
  else{
    char t[20];
    int k = 0; int l = 0;
    while(k < n){
      if(s[k] == 'K' && s[Max(k - 1, 0)] != 'A'){
	t[l++] = 'A';
	t[l++] = 'K';
      }
      else if(s[k] == 'H' && s[k + 1] != 'A'){
	t[l++] = 'H';
	t[l++] = 'A';
      }
      else if(s[k] == 'B' && s[k + 1] != 'A'){
	t[l++] = 'B';
	t[l++] = 'A';
      }
      else if(s[k] == 'R' && s[k + 1] != 'A'){
	t[l++] = 'R';
	t[l++] = 'A';
      }
      else t[l++] = s[k];
      k++;
    }
    t[l] = 0;
    //printf("%s\n", t);
    char x[] = "AKIHABARA\0\0\0\0\0\0\0\0\0\0";
    int cnt = 0;
    for(int i = 0; i < l; i++){
      if(t[i] == x[i])cnt++;
      else break;
    }
    if(cnt == 9) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}
