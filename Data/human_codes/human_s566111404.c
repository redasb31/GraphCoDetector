#include <stdio.h>

int main(){

  int N,M,i,j,a[200000],b[200000],x=1,y=0;
  scanf("%d %d",&N,&M);
  for(i=0;i<M;i++){
    scanf("%d %d",&a[i],&b[i]);
  }

  for(i=0;i<M;i++){
    if(a[i]==1){
      x=b[i];
    }else{
      continue;
      }
    for(j=0;j<M;j++){
      if(a[j]==x && b[j]==N){
        y++;
        break;
        }
    }
      if(y==1){
        break;
      }
  }
  if(y==1){
    printf("POSSIBLE");
  }else{
    printf("IMPOSSIBLE");
  }

  return 0;
}