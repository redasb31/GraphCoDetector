#include <stdio.h>


int main(void){
    int N,M;
    scanf("%d %d",&N,&M);
    double a[N];
    double ruiseki[N+1];
    ruiseki[0]=0;
    for(int i=0;i<N;i++){scanf("%lf",&a[i]);ruiseki[i+1]=ruiseki[i]+a[i];}
    double dp[2][N-M+1][N-M+1];
    for(int i=0;i<2;i++)for(int j=0;j<N-M+1;j++)for(int k=0;k<N-M+1;k++){dp[i][j][k]=-100000000000000;}
    dp[0][0][0]=(double)a[0];
    dp[1][0][0]=(double)a[0];
    for(int i=1;i<N;i++){
        for(int j=0;j<N-M+1&&j<i;j++){
            double max=0;
            for(int k=0;k<=j;k++)if(max<dp[0][j][k])max=dp[0][j][k];
        dp[1][j][0]=max+a[i];
        }
        for(int j=1;j<N-M+1&&j<=i;j++)for(int k=1;k<=j;k++){
            dp[1][j][k]=dp[0][j-1][k-1]+(double)(ruiseki[i+1]-ruiseki[i-k])/(k+1)-(double)(ruiseki[i]-ruiseki[i-k])/k;
        }
        for(int j=0;j<N-M+1;j++)for(int k=0;k<N-M+1;k++)dp[0][j][k]=dp[1][j][k];
    }
    double ans=0;
    for(int k=0;k<N-M+1;k++)if(ans<dp[1][N-M][k])ans=dp[1][N-M][k];
    if(M!=1)printf("%f",ans);
    else printf("%f",dp[1][N-M][N-M]);
    return 0;
}

