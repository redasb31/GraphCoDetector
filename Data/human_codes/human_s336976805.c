#include<stdio.h>
#define M 100000000
int MIN(int a,int b){return a<b?a:b;}
int main(){
  int n,t,l,m,r[110],d[110][110],i,j,k,min,f[110],c[110],mi;
  while(scanf("%d %d %d %d %d %d",&n,&t,&l,&m,&r[0],&r[1]),n){
    for(i=0;i<10000;i++)d[i/100][i%100]=M;
    for(i=0;i<100;i++)d[i][i]=f[i]=0;
    for(i=0;i<100;i++)c[i]=M;
    l+=2;
    for(i=2;i<l;i++)scanf("%d",&r[i]);
    while(m--){
      scanf("%d %d %d",&i,&j,&k);
      d[i][j]=d[j][i]=k;
    }
    for(k=0;k<n;k++){
      for(i=0;i<n;i++){
	for(j=0;j<n;j++)d[i][j]=MIN(d[i][j],d[i][k]+d[k][j]);
      }
    }
    for(c[r[0]]=i=0;i<l;i++){
      min=M;
      for(j=0;j<l;j++){
	if(f[r[j]])continue;
	if(min>c[r[j]])min=c[mi=r[j]];
      }
      f[mi]=1;
      for(j=0;j<l;j++){
	if(d[mi][r[j]]>t)continue;
	c[r[j]]=MIN(c[r[j]],c[mi]+d[mi][r[j]]);
      }
    }
    if(c[r[1]]-M){
      if(c[r[1]]>t)c[r[1]]+=c[r[1]]-t;
      printf("%d\n",c[r[1]]);
    }
    else printf("Help!\n");
  }
  return 0;
}