#include<stdio.h>
#define MIN(a,b) a<b?a:b

int main(){
    int i,j;
    int n;
    int s[3];
    int min=100000001;
    int count=0;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &s[i]);
        min=MIN(min,s[i]);
    }
    for(i=1;i<=min;i++){
        for(j=0;j<n;j++){
            if(s[j]%i)break;
            else count++;
        }
        if(count==n)printf("%d\n", i);
        count=0;
    }

    return 0;
}
