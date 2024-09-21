

#include <stdio.h>

int main(){
    int N, C, p , S;
    int ans;
    
    scanf("%d%d", &N, &C);
    for(S = 0; C > 0; C--){
        scanf("%d", &p);
        S += p;
    }
    ans = S / (N + 1);
    if (S % (N + 1)) ans++;
    printf("%d\n", ans);
    return 0;
}
