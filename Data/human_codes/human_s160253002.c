#include <stdio.h>
#include <string.h>
int const N=2000010;
char s[N];
int a[N];
int main(){
    scanf("%s",s);
    int n=strlen(s);
    long long mmh=1LL*n*(n+1)/2;
    for (int i=0;i<n;i++){
        a[s[i]]++;
        mmh-=a[s[i]];
    }
    printf("%lld\n",mmh);
}