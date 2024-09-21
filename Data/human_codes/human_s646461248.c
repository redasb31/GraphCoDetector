#include<stdio.h>
#include<string.h>
int W,H,N,Cs[2],Ce[2],i,j,k,X,Y,T,c1=0,c2=0,mv[3][2],f;
char S[1005];

int bet(int a,int p,int c)
{
	return (a>c?c:a)<=p&&p<=(a>c?a:c);
}

int ch1(int p[2])
{
	return (p[0]==Cs[0]&&bet(Cs[1],p[1],Ce[1]))||(p[1]==Ce[1]&&bet(Cs[0],p[0],Ce[0]));
}
int ch2(int p[2])
{
	return (p[0]==Ce[0]&&bet(Cs[1],p[1],Ce[1]))||(p[1]==Cs[1]&&bet(Cs[0],p[0],Ce[0]));
}
int main()
{
	scanf("%d%d%d",&W,&H,&N);
	scanf("%d%d%d%d",Cs,Cs+1,Ce,Ce+1);
	for(i=0;i<N;i++)
	{
		scanf("%d%d",&X,&Y);
		scanf("%d %s",&T,S);
		mv[0][0]=X;
		mv[0][1]=Y;
		for(j=0,f=1;j<T;j++)
		{
			for(k=0;k<strlen(S);k++,f++)
			{
				switch(S[k])
				{
				case 'R':if(X<W)X++;break;
				case 'L':if(X>0)X--;break;
				case 'U':if(Y>0)Y--;break;
				case 'D':if(Y<H)Y++;break;
				}
				mv[f%3][0]=X;
				mv[f%3][1]=Y;
				if(f>1&&!ch1(mv[f%3])&&ch1(mv[(f-1+3)%3])&&!ch1(mv[(f-2+3)%3]))
					c1++;
				if(f>1&&!ch2(mv[f%3])&&ch2(mv[(f-1+3)%3])&&!ch2(mv[(f-2+3)%3]))
					c2++;
			}
		}
	}
	printf("%d\n",c1>c2?c2:c1);
	return 0;
}