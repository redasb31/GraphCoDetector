#include<stdio.h>
int main(){
  int a[5000],b[5000],n,m,i,j,k,max=0,c;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  for(i=0;i<m;i++)scanf("%d",&b[i]);
  for(i=0;i<m;i++){
    k=i;
    c=0;
    for(j=0;j<n;j++){
      if(a[j]==b[k]){
	k++;
	c++;
      }
    }
    if(max<c)max=c;
  }
  printf("%d\n",max);
  return 0;
}