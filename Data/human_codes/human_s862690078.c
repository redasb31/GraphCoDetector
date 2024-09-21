#include <stdio.h>
#include <math.h>


int main (){
        unsigned long long N,M;
        unsigned long long count =0;
        scanf("%llu%llu", &N, &M);

        if (N>M) {
              unsigned long long tmp = N;
              N = M;
              M = tmp;
        }

        if (N<=3) {
              if (N ==2) {
                      count =0;
              }else{
                      if (M==1 || M==3) {
                            count =1;
                      }else if (M==2) {
                            count =0;
                      }else{
                            count = M*N - 2*N;
                      }
              }
        }else{
          count =(N-2)*(M-2);
        }

        printf("%llu\n",count );
        return 0;
}
