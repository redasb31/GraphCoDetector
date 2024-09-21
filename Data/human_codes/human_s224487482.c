#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{   int i;
    long long a[100001],n,ans,cnt=0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        
    }
    for(i=0;i<n;i++){
        while(a[i]>=2){
            if(a[i]%2==0){
            a[i]=a[i]/2;
            cnt++;
            }else break;
        }
    }
    printf("%lld",cnt);
    return 0;
}
