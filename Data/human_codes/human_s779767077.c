#include<stdio.h>
#include<stdlib.h>

int *SoE (int n,int *plist) {
  int list[n-1];
  int i,j;

  for(i=2; i<n+1; i++) list[i-2] = i;

  for(j=2; j*j<n+2; j++) {
    if(list[j-2]!=0) {
      for(i=1; j-2+list[j-2]*i < n; i++) {
	list[j-2+list[j-2]*i] = 0;
      }
    }
  }

  j=1;
  for(i=0; i<n; i++) {
    if(list[i]!=0) *(plist+j) = list[i],j++;
  }

  *plist = j-1;

  return plist;
}

int isPrime (int n, int *plist) {

  int p = *plist;
  int i;
  for(i=1; i<=p; i++) if(*(plist+i) == n) return 1;

  return 0;
}

int main() {

  int *plist;
  plist = malloc(sizeof(int)*10000);
  if(plist==NULL) return -1;

  plist = SoE(10000,plist);

  int j;
  int N=0;
  int c=0;
  while(scanf("%d",&N) != EOF) {
    for(j=1; j<=N; j++) if( (isPrime(j,plist) + isPrime(N-j+1,plist)) == 2) c++;
    printf("%d\n",c);
    c=0;
  }
  return 0;
}