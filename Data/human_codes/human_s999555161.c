sum[3<<17],cnt[3<<17];
N,i,acc,t,k,x;
char f[10];
char buf[2200000];
sz;
main()
{
	read(0,buf,2200000);
	for(;;)
	{
		k=buf[sz++];
		if(k<'0')break;
		N=N*10+k-'0';
	}
	for(i=0;i<N;i++)
	{
		x=0;
		for(;;)
		{
			k=buf[sz++];
			if(k<'0')break;
			x=x*10+k-'0';
		}
		++sum[cnt[x]++];
	}
	i=sz=0;
	for(t=N;t;t--)
	{
		while(acc>=i*t)acc+=sum[i++];
		cnt[t]=i-1;
	}
	for(i=1;i<=N;i++)
	{
		if(!cnt[i])
		{
			buf[sz++]='0';
		}
		else
		{
			if(cnt[i-1]!=cnt[i])
			{
				k=0;
				t=cnt[i];
				while(t)
				{
					f[k++]=t%10;
					t/=10;
				}
				acc=k;
			}
			else k=acc;
			while(k--)buf[sz++]=f[k]+'0';
		}
		buf[sz++]='\n';
		if(sz>100000)
		{
			write(1,buf,sz);
			sz=0;
		}
	}
	write(1,buf,sz);
}