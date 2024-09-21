#include<stdio.h>
int main(){
  int n,i,j,ans=0,c[30],p[1010][30],a,b[30]={};
  scanf("%d",&n);
  for(i=0;i<26;i++)scanf("%d",&c[i]);
  for(i=0;i<n;i++){
    for(j=0;j<26;j++)scanf("%d",&p[i][j]);
  }
  for(i=1;i<=n;i++){
    scanf("%d",&a);
    ans+=p[i-1][a-1];
    b[a-1]=i;
    for(j=0;j<26;j++)ans-=c[j]*(i-b[j]);
    printf("%d\n",ans);
  }
  //printf("%d\n",ans);
  return 0;
}
