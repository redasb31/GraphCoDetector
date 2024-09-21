#include <stdio.h>

int main(void)
{
  int t[201]={0};
  int taro[100]={0};
  int  hana[100]={0};
  int i, j, k, tmp, n ,now, tc, hc;
  tc = hc = 0;

  while(1){
    scanf("%d", &n);
    if(n == 0) break;
    for(i = 0; i < n; i++){
      scanf("%d", &tmp);
      t[tmp] = 1;
    }

    j = k = 0;
    for(i = 1; i <= 2*n; i++){
      if(t[i] == 0)
	hana[j++] = i;
      else
	taro[k++] = i;
    }

    j = k = n;
    now = taro[0];
    taro[0] = 0;
    while(j != 0 && k-1 != 0){
      for(i = 0; i < n; i++){
	  if(now < hana[i]){
	  now = hana[i];
	  hana[i] = 0;
	  j--;
	  break;
	  }
	}
      if(i == n) now = 0;

	for(i = 1; i < n; i++){
	  if(now < taro[i]){
	    now = taro[i];
	    taro[i] = 0;
	    k--;
	    break;
	  }
	}
	if(i == n) now = 0;
      }
    for(i = 0; i < n; i++){
      if(taro[i] != 0) tc++;
      if(hana[i] != 0) hc++;
    }
      printf("%d\n%d\n", hc, tc);
  }
  return 0;
}