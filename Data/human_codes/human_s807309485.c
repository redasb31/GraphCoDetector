#include <stdio.h>
#include <stdlib.h>


// メイン関数
int main(void) {
    int n = 0;
    scanf("%d",&n);

    int w[n];
    for(int i = 0;i < n;i++) scanf("%d",&w[n]);

    int s[2];
    int min = 0;
    for(int t = 0;t < n;t++){
        s[0] = 0;
        s[1] = 0;
        for(int i = 0;i < n;i++){
            if(w[n] <= t) s[0] += w[n];
            else s[1] += w[n];
        }
        if(t == 0 || min > abs(s[0]-s[1])) {
            min = abs(s[0]-s[1]);
        }
    }

    printf("%d", min);


    return 0;
}

