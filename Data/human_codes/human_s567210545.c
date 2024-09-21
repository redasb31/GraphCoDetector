#include<stdio.h>
//int asd(int ,int *,int *);
int main(void){
  int m,d,ans=0,ef=0;
  int *ten,*one;
  scanf("%d%d",&m,&d);
  if(m<4||d<22){
    printf("0");
    return 0;
  }
  for(int i=4;i<=m;i++){
   ef=0;
    for(int j=2;j<=9;j++){
      if(ef)break;
      for(int k=2;k<=9;k++){
        if(10*j+k>d){ef=1;
                     break;
                    }
       // printf("%d %d %d\n",j,k,i);
        if(j*k==i)ans++;
      }
    }
  }
  
  printf("%d",ans);
  return 0;
}