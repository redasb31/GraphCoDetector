#include<stdio.h>
#include<stdlib.h>

typedef long long int int64;

#define POS(i,j) ((i)*n+(j))

void sieve(char *p,int n){
  int i,j;
  for(i=2;i<=n;i++) p[i]=1;
  p[0]=p[1]=0;
  for(i=2;i*i<=n;i++){
    if(!p[i]) continue;
    for(j=i*i;j<=n;j+=i) p[j]=0;
  }
  return;
}

void run(void){
  const int n=500;
  char *p=(char *)malloc(sizeof(char)*8001);
  sieve(p,8000);
  int *l=(int *)malloc(sizeof(int)*2*n);
  int *r=(int *)malloc(sizeof(int)*2*n);
  int lp=0;
  int rp=0;
  int i=2;
  while(lp<2*n){
    l[lp++]=i++;
  }
  while(rp<2*n){
    if(p[i]) r[rp++]=i;
    i++;
  }
  int64 *board=(int64 *)malloc(sizeof(int64)*n*n);
  int j;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if((i+j)%2==0){
	board[POS(i,j)]=l[(i+j)/2]*r[((n-i)+j)/2];
      } else {
	int64 local=(int64)l[(i+j)/2]*l[(i+j)/2+1]*r[((n-i)+j)/2]*r[((n-i)+j)/2+1];
	board[POS(i,j)]=local+1;
      }
    }
  }
  int m;
  scanf("%d",&m);
  for(i=0;i<m;i++){
    printf("%lld",board[POS(i,0)]);
    for(j=1;j<m;j++){
      printf(" %lld",board[POS(i,j)]);
    }
    printf("\n");
  }
}

int main(void){
  run();
  return 0;
}
