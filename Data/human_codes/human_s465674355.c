#include<stdio.h>
#include<math.h>
#define ll long long
int main()
{
    ll N,i,t=1,a=1;
    scanf("%lld",&N);
    ll A[N+1],l[N+1];
    for(i=0;i<N+1;i++)scanf("%lld",&A[i]);
    l[N]=A[N];
    for(i=N-1;i>0;i--)l[i]=A[i]+l[i+1];
    for(i=1;i<=N;i++){
        if(2*t<A[i]){
            a=-1;
            break;
        }
        if(t*2<l[i])t*=2;
        else t=l[i];
        a+=t;
        t-=A[i];
    }
    if(A[0]!=0)a=-1;
    if(N==0 && A[0]==1)a=1;
    printf("%lld",a);
    return 0;
}