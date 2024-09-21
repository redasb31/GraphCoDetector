#define D(i,a,b)for(int i=a;i>=b;--i)
f[2005],n,k,M=1e9+7;main(){scanf("%d%d",&n,&k);f[n+1]=1;D(i,n,n-k+1)D(j,n,1)f[j]=j>i?0:(f[j]+f[j+1])%M;D(i,n-k,2)(f[1]*=2)%=M;printf("%d\n",f[1]);}