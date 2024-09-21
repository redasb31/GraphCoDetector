#include<stdio.h>

int main(){

        long int n, i;
        scanf("%ld", &n);
        long long a;
        long long res=1;
        for(i=0; i<n; i++){
                scanf("%lld", &a);
                res*=a;
        }
        if(res>1000000000000000000){
                printf("-1");
        }else{
                printf("%lld", res);
        }

        return 0;
}
