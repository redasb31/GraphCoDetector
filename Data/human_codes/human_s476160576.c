long mod=1e9+7,dp[1<<21];
n,a,I,x,y,i,j;
main()
{
	for(*dp=scanf("%d",&n);i++<n;)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a);
			for(I=(1<<i)-1;I<1<<n;)
			{
				if(a&&(I&1<<j))dp[I]=(dp[I]+dp[I&~(1<<j)])%mod;
				x=I&-I,y=I+x;
				I=(I&~y)/x>>1|y;
			}
		}
	}
	printf("%d",dp[I-y/2]);
}