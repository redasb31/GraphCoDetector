#include<stdio.h>
long long MIN(long long a,long long b){return a<b?a:b;}
long long i,j,d[2010][2010],x[200010],m;
int main(){
  int n;
  scanf("%d %lld",&n,&m);
  for(i=0;i<n;i++)scanf("%lld",&x[i]);
  if(n>2005)return 0;
  for(i=0;i<2005;i++){
    for(j=0;j<2005;j++)d[i][j]=1e18;
  }
  d[n][n-1]=x[n-1]+m;
  for(i=n+1;i--;){
    for(j=i;j--;){
      d[i][j-1]=MIN(d[i][j-1],d[i][j]+(i-j+1)*(i-j+1)*(x[j]-x[j-1])+m  );
      d[j][j-1]=MIN(d[j][j-1],d[i][j]+(i-j+1)*(i-j+1)* x[j]+x[j-1] +m+m);
    }//printf("a\n");
  }//printf("a\n");
  /*for(i=0;i<=n;i++){
    for(j=0;j<=n;j++)printf("%20lld ",d[i][j]);printf("\n");
    }//*/
  for(i=1;i<=n;i++)d[0][0]=MIN(d[0][0],d[i][0]+x[0]*(i+1)*(i+1)+m);
  printf("%lld\n",d[0][0]);
}
