#include<stdio.h>
#include<string.h>
#include<math.h>

int N,S,A,C,R[257],I[257],X[257],i,j,rS,rA,rC;
double H,r;
int main()
{
	for(;scanf("%d",&N),N;)
	{
		for(i=0,r=-1;i<N;i++)
			scanf("%d",&I[i]);
		for(S=0;S<16;S++)
			for(A=0;A<16;A++)
				for(C=0;C<16;C++)
				{
					memset(X,0,sizeof(X));
					for(R[0]=S,i=1;i<=N;i++)
						R[i]=(A*R[i-1]+C)%256;
					for(i=0;i<N;i++)
						X[(I[i]+R[i])%256]++;
					for(H=i=0;i<256;i++)
					{
						if(X[i])
						{
							double tmp=(double)X[i]/N;
							double Log=log(tmp);
							H+=-tmp*Log;
						}
					}
					if(r==-1||r-H>0.0000001)
					{
						rS=S;
						rA=A;
						rC=C;
						r=H;
					}
				}
		printf("%d %d %d\n",rS,rA,rC);
	}
	return 0;
}