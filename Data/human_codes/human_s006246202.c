#include <stdio.h>
#include <stdlib.h>
int main()
{   long long n,ans=0;
    scanf("%lld",&n);
    for(long long c=1;c<n;c++){
        long long lim=sqrt(n-c);
        for(long long a=1;a<=lim;a++){
            if((n-c)%a==0){
                ans++;
                if(n-c!=a*a){
                    ans++;
                }
            }
        }
    }
    printf("%lld",ans);
    
    return 0;
}
