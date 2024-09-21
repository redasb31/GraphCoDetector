#include<stdio.h>
int p[110][5],m;
int f(int a,int b,int c,int d){
  int k;
  for(k=0;k<m;k++){
    if(p[k][0]==a&&p[k][1]==b&&p[k][2]==c&&p[k][3]==d||
       p[k][0]==c&&p[k][1]==d&&p[k][2]==a&&p[k][3]==b)return 0;
  }
  return 1;
}
int main(){
  int n,w,h,i,j;
  scanf("%d",&n);
  while(n--){
    int d[20][20]={1};
    scanf("%d %d %d",&h,&w,&m);
    for(i=0;i<m;i++){
      for(j=0;j<4;j++)scanf("%d",&p[i][j]);
    }
    for(i=0;i<=h;i++){
      for(j=0;j<=w;j++){
	d[i+1][j]+=d[i][j]*f(i,j,i+1,j);
	d[i][j+1]+=d[i][j]*f(i,j,i,j+1);
      }
    }
    d[h][w]?printf("%d\n",d[h][w]):printf("Miserable Hokusai!\n");
  }
  
  return 0;
}