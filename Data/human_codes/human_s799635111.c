#include<stdio.h>
int main(){
  int n,m,d[2][3],o[2][3],i,j;
  double h,l,p[3],k;
  long long s[60][5],ans=0;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++){
    for(j=0;j<5;j++)scanf("%lld",&s[i][j]);//,printf("%lld ",s[i][j]);printf("\n");
  }
  while(m--){
    for(i=ans=0;i<6;i++)scanf("%d",&o[i/3][i%3]);
    for(j=0;j<3;j++)d[0][j]=o[1][j]-o[0][j];//,printf("%d ",d[0][j]);printf("\n");
    for(j=l=0;j<3;j++)l+=d[0][j]*d[0][j];//printf("l%lf\n",l);
    for(i=0;i<n;i++){
      for(j=  0;j<3;j++)d[1][j]=s[i][j]-o[0][j];//,printf("%d ",d[1][j]);printf("\n");
      for(j=h=0;j<3;j++)h+=d[0][j]*d[1][j];//printf("h%lf\n",h);
      if(h>l)continue;
      for(j=  0;j<3;j++)p[j]=h/l*d[0][j]+o[0][j];//,printf("%f ",p[j]);printf("\n");
      for(j=k=0;j<3;j++)k+=(p[j]-s[i][j])*(p[j]-s[i][j]);//printf("k%f\n",k);
      if(s[i][3]*s[i][3]>k-0.000000001)ans+=s[i][4];//printf("s%lld\n",s[i][3]*s[i][3]);
    }//printf("%d\n",i);
    printf("%lld\n",ans);
  }
  return 0;
}