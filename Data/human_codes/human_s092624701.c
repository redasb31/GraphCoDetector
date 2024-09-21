#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define RFOR(i,a,b) for(i=(b);i>=(a);i--)
#define REP(i,n) for(i=0;i<(n);i++)
#define RREP(i,n) for(i=(n)-1;i>=0;i--)
#define MREP(i,n,x) for(i=0;i<(n);i=x)
#define IL() while(1)
#define mLOOP(a,b) while((a)<(b)) 
#define MLOOP(a,b) while((a)>(b))
#define ELOOP(a,b) while((a)==(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define ABS(x) ((x)<0?-1*(x):(x))
#define in scanf
#define out printf
#define ll long long
#define ull unsigned long long
#define int(x) scanf("%d",&x);
#define sint(x,y) scanf("%d %d",&x,&y);
#define lint(x,y) scanf("%d\n%d",&x,&y);
#define char(x) scanf("%c",&x);
#define double(x) scanf("%lf",&x);
#define string(x,n) scanf("%s",x);

ull gcd(ull a,ull b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    ull n,x,i,res;
    in("%lld %lld",&n,&x);
    res = 3*(n-gcd(n,x));
    out("%lld\n",res);
    return 0;
}