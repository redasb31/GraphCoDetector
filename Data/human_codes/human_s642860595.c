#include<stdio.h>
int main(){
  int n,i,j,count=0;
  int a[11][11];
  for(i=0;i<10;i++)
    for(j=0;j<10;j++)
      a[i][j]=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    j=i;
    while(j/10!=0)
      j/=10;
    a[j][i%10]++;
  }
  for(i=1;i<=9;i++){
    for(j=i;j<=9;j++){
      if(i==j)
        count+=a[i][j]*a[i][j];
      else
        count+=2*a[i][j]*a[j][i];
    }
  }
  printf("%d\n",count);
  return 0;
}
