#include<stdlib.h>
#include<stdio.h>

int main(){
  long N,over,s[9],j,ans,i,k,h;
  over = 0;
  ans = 0;
  for(h=0;h<8;h++){
    s[h]=0;
  }
  scanf("%ld",&N);

  for(i=0;i<N;i++){
    scanf("%ld",&j);

    if(1<=j && j<=399){
        k = 0;
      }else if(400<=j && j<=799){
        k = 1;
      }else if(800 <= j && j <= 1199){
        k = 2;
      }else if(1200<=j && j<=1599){
        k = 3;
      }else if(1600<=j && j<=1999){
        k = 4;
      }else if(2000<=j && j<=2399){
        k = 5;
      }else if(2400<=j && j<=2799){
        k = 6;
      }else if(2800<=j && j<=3199){
        k = 7;
      }else if(3200<=j){
        k = 8;
      }
      if(k == 8){
        over +=1;
      }else if(s[k] == 0){
        ans += 1;
        s[k] = 1;
      }
    }

    printf("%ld %ld\n",ans,ans+over);


    return 0;
}
