#include<stdio.h>
int main()
{
	int a,b,c,d,n,i,j,r[101]={0},s[101]={0};
	scanf("%d",&n);
	for(i=0;i<n*(n-1)/2;i++,c==d?r[a]++,r[b]++:c>d?r[a]+=3:r[b]+=3)
		scanf("%d%d%d%d",&a,&b,&c,&d);
	for(i=0;i<n;s[i]=c,i++)
		for(j=1,c=0,d=i==0?100000:s[i-1];j<=n;j++)
		{
			if(d>r[j]&&c<r[j])
					c=r[j];
		}
	for(i=1;i<=n;i++)
	{
		for(j=0;s[j]!=r[i];j++);
			printf("%d\n",j+1);
	}
	return 0;
}a