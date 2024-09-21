long M=998244353,d[90310],e[90310],s=0,r=1;
a;t;
main(){
d[0]=e[0]=1;
for(scanf("%*d");~scanf("%d",&a);){
for(t=s;~t;--t)d[t+a]+=d[t]*2%M,e[t+a]+=e[t]%M;
s+=a;
r=r*3%M;
}
for(t=s/2;~t;--t)r=(r-d[t]*3)%M;
r=(r+~s%2*e[s/2]*3+M)%M;
printf("%d",r);
}