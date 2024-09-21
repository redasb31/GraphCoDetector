#include<stdio.h>
int main(){
  int n,m,s,e,w,i,j,l,mi,min,a,b,r;
  while(scanf("%d %d %d %d %d",&w,&n,&m,&s,&e),w){
    int d[110][110]={0};
    while(m--){
      scanf("%d %d %d",&a,&b,&r);
      d[a][b]=d[b][a]=r;
    }
    int c[12][110]={0};
    for(i=0;i<=w;i++){
      mi=s;
      int f[110]={0};
      for(l=0;l<n;l++){
	f[mi]=1;
	for(j=1;j<=n;j++){
	  if(d[mi][j]==0)continue;
	  if(c[i][j]==0||c[i][j]>c[i  ][mi]+d[mi][j]){
	    c[i][j]=c[i][mi]+d[mi][j];
	  }
	  if(c[i+1][j]==0||c[i+1][j]>c[i+1][mi]+d[mi][j]/2){
	    c[i+1][j]=c[i][mi]+d[mi][j]/2;
	  }
	}
	min=2100000000;
	for(j=1;j<=n;j++){
	  if(f[j]||c[i][j]==0)continue;
	  if(min>c[i][j])min=c[i][mi=j];
	}
      }
    }
    min=2100000000;
    for(i=0;i<=w;i++){
      if(c[i][e]==0)continue;
      if(min>c[i][e])min=c[i][e];
    }
    printf("%d\n",min);
  }
  return 0;
}