#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MIN(x,y) (((x)<(y))?(x):(y))
#define INFTY (1<<21)


int m, n, k, d, C[7], G[110][110], N, D[110][64];

int getID(char *str);
int isC(int x);
int bellman(void);

int main(void){
  char source[16], target[16];
  int cost,s,t;
  int i,j;
  while(scanf("%d%*c%d%*c%d%*c%d%*c",&m,&n,&k,&d) && m ){
    N = 2 + n + m;
    for(i=1;i<m+1;i++) scanf("%d%*c",&C[i]);
    for(i=0;i<N;i++) for(j=0;j<N;j++) G[i][j] = INFTY;
    for(i=0;i<d;i++){
      scanf("%s%*c%s%*c%d%*c",source,target,&cost);
      s = getID(source);
      t = getID(target);
      G[t][s] = G[s][t] = MIN(G[s][t], cost * k);
    }
    printf("%d\n",bellman());
  }
  return 0;
}

int getID(char *str){
  char num[16];
  if ( str[0] == 'H' ) return 0;
  if ( str[0] == 'D' ) return N - 1;
  strcpy(num,str+1);
  if ( str[0] == 'C' ) return atoi(num);
  return atoi(num) + m;
}

int isC(int x){
  return (1 <= x) && (x <= m);
}

int bellman(void){
  bool change;
  int minv;
  int i,i1,i2,i3,i4,j;

  for(i=0;i<N;i++) for(j=0;j<(1<<m);j++) D[i][j] = INFTY;
  D[0][0] = 0;
  for(i1=0;i1<N*(1<<m);i1++){
	change=false;
    for(i2=0;i2<N;i2++){
      for(i3=0;i3<N;i3++){
	if ( i2 == i3 || G[i2][i3] == INFTY ) continue;
	for(i4=0;i4<(1<<m);i4++){
	  if (isC(i3) && (i4&(1<<(i3-1))) != 0 ) continue;
	  if ( isC(i3) ) {
	    if ( D[i2][i4] + G[i2][i3] - C[i3] < D[i3][i4|(1<<(i3-1))] ) {
	      D[i3][i4|(1<<(i3-1))] = D[i2][i4] + G[i2][i3] - C[i3];
	      change = true;
	    }
	  } else {
	    if ( D[i2][i4] + G[i2][i3] < D[i3][i4] ){
	      D[i3][i4] = D[i2][i4] + G[i2][i3];
	      change = true;
	    }
	  }
	}
      }
    }
    if ( !change ) break;
  }
  minv = INFTY;
  for(i=0;i<(1<<m);i++) minv = MIN(minv, D[N-1][i]);
  return minv;
}