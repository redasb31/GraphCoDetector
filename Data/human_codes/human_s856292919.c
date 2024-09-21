#include <stdio.h>

int main(){
  int n,m,big,i,f=0,count=0;
  scanf("%d %d",&n,&m);
  int L[200000],R[200000],D[200000];
  for(i=0;i<m;i++){
    scanf("%d %d %d",&L[i],&R[i],&D[i]);
  }
  int x[200000],y[200000],z[200000];
  for(i=0;i<m;i++){
    x[i]=0;
    y[i]=0;
    z[i]=0;
  }
  for(big=0;big>=0;big++){
    for(i=0;i<m;i++){
      if(i==0){
        x[L[i]]=1;
        x[R[i]]=1;
        y[L[i]]=0;
        y[R[i]]=D[i];
        count += 1;
      }else{
        if(x[L[i]]==1 && x[R[i]]==1){
          if(y[R[i]]-y[L[i]]!=D[i]){
            f = 1;
            break;
          }
        }else if(x[L[i]]==0 && x[R[i]]==0){
          if(big==3){
            y[L[i]]=0;
            y[R[i]]=D[i];
          }          
        }else if(x[L[i]]==0 && x[R[i]]==1){
          y[L[i]]=y[R[i]]-D[i];
          x[L[i]]=1;
          z[i]=1;
          count += 1;
        }else{
          y[R[i]]=y[L[i]]+D[i];
          x[R[i]]=1;
          z[i]=1;
          count += 1;
        }
      }
    }
      if(count==m-1 && big ==0){
      if(f==1){
        printf("No\n");
        big = -1;
        break;
      }else{
        printf("Yes\n");
        big = -1;
        break;
      }
    }
    if(big == 20 && f==0){
      printf("Yes\n");
      break;
    }
  }
  return 0;
}