#include<stdio.h>
#include<string.h>
int P,Q,cp[11][8],cq[11][8],i,j,k,f,T[21][21][21],R,C,S;
char t,a[]="(){}[]";

void in(int N,int I[11][8])
{
	for(i=0;i<N;i++)
	{
		for(f=1;(t=getchar())!=10;)
		{
			if(t!='.')f=0;
			if(f)I[i][0]++;
			for(k=0;k<6;k++)
				if(t==a[k])
					I[i][k+1]++;
		}
	}
}

int main()
{
	for(;scanf("%d%d\n",&P,&Q),P;)
	{
		memset(T,-1,sizeof(T));
		memset(cp,0,sizeof(cp));
		memset(cq,0,sizeof(cq));
		in(P,cp);in(Q,cq);
		R=C=S=-1;
		for(i=1;i<=20;i++)
			for(j=1;j<=20;j++)
				for(k=1;k<=20;k++)
				{
					int cR=cp[0][1]-cp[0][2];
					int cC=cp[0][3]-cp[0][4];
					int cS=cp[0][5]-cp[0][6];
					int ch;
					for(ch=1;ch<P;ch++)
					{
						if(i*cR+j*cC+k*cS!=cp[ch][0])
							break;
						T[cR][cC][cS]=cp[ch][0];
						cR+=cp[ch][1]-cp[ch][2];
						cC+=cp[ch][3]-cp[ch][4];
						cS+=cp[ch][5]-cp[ch][6];
					}
					if(ch==P)
					{
						if(R==-1&&C==-1&&S==-1)
						{
							R=i;C=j;S=k;
						}
						else
						{
							R=C=S=-1;
							goto e;
						}
					}
				}
e:;

		int cR=cq[0][1]-cq[0][2];
		int cC=cq[0][3]-cq[0][4];
		int cS=cq[0][5]-cq[0][6];
		for(printf("0%s",Q==1?"\n":" "),i=1;i<Q;i++)
		{
			if(cR<=20&&cC<=20&&cS<=20&&T[cR][cC][cS]!=-1)
				printf("%d%s",T[cR][cC][cS],i==Q-1?"\n":" ");
			else if((cR&&R==-1)||(cC&&C==-1)||(cS&&S==-1))
				printf("-1%s",i==Q-1?"\n":" ");
			else
				printf("%d%s",cR*R+cC*C+cS*S,i==Q-1?"\n":" ");
			cR+=cq[i][1]-cq[i][2];
			cC+=cq[i][3]-cq[i][4];
			cS+=cq[i][5]-cq[i][6];
		}
	}
	return 0;
}