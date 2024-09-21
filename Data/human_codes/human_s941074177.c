#include<stdio.h>
typedef unsigned long long ll;

ll gcd(ll a, ll b){
        ll tmp;
        if(a<b){
                tmp = a;
                a = b;
                b = tmp;
        }
        while(b){
                tmp = a;
                a = b;
                b = tmp%b;
        }
        return a;
}

ll lcm(ll a, ll b){
        return a / gcd(a, b) * b;
}


ll main(void){
        ll n; scanf("%llu", &n);
        ll a[n], i;
        for(i=0; i<n; i++) scanf("%llu", &a[i]);

        ll ans = 0;
        for(i=1; i<(1<<n); i++){
                ll tmp=1, j;
                for(j=0; j<n; j++){
                        if((i>>j)&1) tmp = lcm(tmp, a[j]);
                }
                ll can = 1;
                for(j=0; j<n; j++){
                        if(((i>>j)&1)==0 && tmp%a[j]==0) can = 0;
                }
                ans += can;
        }

        printf("%llu\n", ans);
        return 0;
}

