#include<stdio.h>
#include<string.h>

#define ULLI long long int
#define UI int

ULLI M=998244353;
UI DP[3][90001];
UI DDP[3][90001];


ULLI modpow(UI a,UI b, UI m){
    return b==0 ? 1 : b%2==1 ? (modpow(a,b-1,m)*a)%m : modpow((a*a)%m,b/2,m);
}


int main(void){
    int N;
    int A[300];
    int sum;
    int sum2;
    UI ret;
    UI overNum=0;
    UI (*dp)[90001]=DP;
    UI (*ddp)[90001]=DDP;
    UI (*temp)[90001];

    fscanf(stdin,"%d",&N);
    sum=0;
    for(int i=0;i<N;i++){
        fscanf(stdin,"%d",&A[i]);
        sum+=A[i];
    }
    sum2=(sum+1)/2;

    dp[0][0]=1;
    for(int i=0;i<N;i++){
        memset(ddp,0,sizeof(UI)*90001*3);
        UI ai=A[i];
        for(int j=0;j<90001;j++){
            if(ai+j<90001){
                ddp[0][j+ai]=(ddp[0][j+ai]+dp[0][j])%M;
                ddp[1][j+ai]=(ddp[1][j+ai]+dp[1][j])%M;
                ddp[2][j+ai]=(ddp[2][j+ai]+dp[2][j])%M;
            }
            ddp[2][j]=((dp[1][j]*2%M+dp[2][j]*2%M)%M+ddp[2][j])%M;
            ddp[1][j]=((dp[0][j]+dp[1][j])%M+ddp[1][j])%M;
        }
        temp=ddp;
        ddp=dp;
        dp=temp;
    }
    for(int i=sum2;i<90001;i++){
        overNum=(overNum+dp[2][i])%M;
    }
    

    ret=(modpow(3,N,M)-3*modpow(2,N,M)%M)%M;
    ret=(ret-3*overNum%M)%M;
    ret=(ret+3)%M;
    printf("%lld\n", ret<0 ? M+ret : ret);
    return 0;    
}