#include<stdio.h>

int main(){

    int N;
    scanf("%d", &N);

    int h[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &h[i]);
    }

    int highest = 0;

    for (int i = 0; i < N; i++){

        if(highest < h[i]){
            highest = h[i];
        }
    }

    int ans = 0;

    for (int i = 0; i < highest; i++){

        int judge;

        if(h[0] > 0){
            judge = 1;
        }else{
            judge = 0;
        }

        for (int n = 0; n < N - 1; n++){

            if((h[n]<=0)&&(h[n+1]>0)){
                judge += 1;
            }
        }

        for (int n = 0; n < N; n++){
            h[n] -= 1;
        }

        ans += judge;
    }

    printf("%d", ans);

    return 0;
}