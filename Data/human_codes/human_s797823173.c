#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		{
			break;
		}
		int i,a,c,d,f[105],g[105],e;
		f[1]=0;
		g[1]=0;
		f[2]=0;
		g[2]=0;
		f[3]=0;
		g[3]=0;
		char b;
		for(i=1;i<=n;i++)
		{
			scanf("%d%c%d%d",&a,&b,&c,&d);
			if(a>=11&&a<=14)
			{
				e=d-c;
				if(e<0)
				{
					e=e+60;
					a=a+1;
				}
				if(a!=15)
				{
					g[1]++;
				}
				if(e<=8&&a<15)
				{
					f[1]++;
				}
			}
			else if(a>=18&&a<=20)
			{
				e=d-c;
				if(e<0)
				{
					e=e+60;
					a++;
				}
				if(a!=21)
				{
					g[2]++;
				}
				if(e<=8&&a<=20)
				{
					f[2]++;
				}
			}
			else if(a>=21||a<2)
			{
				e=d-c;
				if(e<0)
				{
					e=e+60;
					a++;
				}
				if(a!=2)
				{
					g[3]++;
				}
				if(e<=8&&(a<=2||a>=21))
				{
					f[3]++;
				}
			}
		}
		if(g[1]==0)
		{
			printf("lunch no guest\n");
		}
		else
		{
			printf("lunch %d\n",f[1]*100/g[1]);
		}
		if(g[2]==0)
		{
			printf("dinner no guest\n");
		}
		else
		{
			printf("dinner %d\n",f[2]*100/g[2]);
		}
		if(g[3]==0)
		{
			printf("midnight no guest\n");
		}
		else
		{
			printf("midnight %d\n",f[3]*100/g[3]);
		}
	}
	return 0;
}