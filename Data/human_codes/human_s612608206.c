#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MAXN 1010
using namespace std;

bool text(long long x)
{
	int a,b=-1;
	while(x>0)
	{
		a=x%10;
		if(b>=0 && a!=b-1)
			return false;
		b=a;
		x/=10;
	}
	return true;
}

int a[MAXN];

int main()
{
	int n;
	long long ans=-1;
	scanf("%d",&n);
	for(int i=0;i!=n;++i)
		scanf("%d",&a[i]);
	for(int i=0;i!=n;++i)
		for(int j=i+1;j<n;++j)
		{
			if(text((long long)(a[i]*a[j])))
				ans=max(ans,(long long)(a[i]*a[j]));
		}
	printf("%lld\n",ans);
}