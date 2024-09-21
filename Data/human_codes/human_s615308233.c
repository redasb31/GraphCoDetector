#include<stdio.h>
int main(void){
    int dp[1000][8],n,i,j,k,ans=0;
    char res[1001];
    scanf("%d",&n);
    scanf("%s",res);
    for(i=0; i<n; i++){
        switch(res[i]){
            case 'J':
                res[i]=4;
                break;
            case 'O':
                res[i]=2;
                break;
            case 'I':
                res[i]=1;
                break;
        }
    }
    for(i=0; i<8; i++){
        if((i&4) != 0 && (i&res[0]) != 0){
            dp[0][i]=1;
        }else{
            dp[0][i]=0;
        }
        for(j=1; j<n; j++){
            dp[j][i]=0;
        }
    }
    for(i=1; i<n; i++){
        for(j=0; j<8; j++){
            for(k=0; k<8; k++){
                if((j&k)!=0 && (res[i]&k)!=0){
                    dp[i][k] = (dp[i][k] + dp[i-1][j])%10007;
                }
            }
        }
    }
    n--;
    for(i=0; i<8; i++){
        ans += dp[n][i];
        ans %= 10007;
    }
    printf("%d\n",ans);
    return 0;
}