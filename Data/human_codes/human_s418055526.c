# include <stdio.h>
# include <math.h>

int main(){
  int N,K;
  double a;
  double b=0;
  scanf("%d %d",&N,&K);
  for(int n=1;n<=N;n++){
    a=0;
    for(int i=1;i>0;i++){
      if(K<=n){
        break;
      }
      if(pow(2,a+1)<=K/n){
      a=a+1;
      }else{
        a=a+1;
        break;
      }
    }
    double p=pow(2,a);
    b=b+1/p;
  }
  printf("%.9lf",b/(double)N);
  return 0;
}