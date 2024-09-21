#include <stdio.h>

int isPrime(int n){
    if(n==2)return 1;
    for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
    return 1;
}

int main(void){
    const int  yamada = 1e9+7;
    int N;
    scanf("%d",&N);
   // for(int i=0;i<1145140;i++)prime[i]=1;
   // prime[1]=0;
   // prime[2]=1;
    //for(int i=3;i<1145140;i++)for(int j=2;j*j<=i;j++){if(i%j==0)prime[i]=0;}
    long long int po[2];
    po[0]=1;
    po[1]=0;
    int a[N+2];
    a[0]=1;
    a[1]=1;
    for(int i=2;i<N+2;i++){scanf("%d",&a[i]);
        long long int kari[2];
        kari[0]=po[0];
        kari[1]=po[1];
        po[0]=isPrime(a[i])*((a[i-1]<a[i])*kari[0]+(a[i-2]<a[i])*kari[1]);
        po[0]%=yamada;
        if(i>2)po[1]=kari[0];
        po[1]%=yamada;
       // printf("%lld %lld\n",po[0],po[1]);
    }
    po[0]+=po[1];
    po[0]%=yamada;
    printf("%lld\n",po[0]);
    return 0;
}

