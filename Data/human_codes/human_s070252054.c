#include<stdio.h>
#include<string.h>
int N,i,j,k,L;
char P[7],M[30],t,T[30];
int main()
{
	for(scanf("%d\n",&N);N--;)
	{
		gets(P);gets(M);
		L=strlen(M);
		for(i=strlen(P)-1;i>=0;i--)
		{
			switch(P[i])
			{
			case 'J':t=M[L-1];memmove(M+1,M,L-1);M[0]=t;break;
			case 'C':t=M[0];memmove(M,M+1,L-1);M[L-1]=t;break;
			case 'E':for(j=0;j<L/2;j++){t=M[j];M[j]=M[j+L/2+L%2];M[j+L/2+L%2]=t;}break;
			case 'A':for(j=0,k=L-1;j<k;j++,k--){t=M[j];M[j]=M[k];M[k]=t;}break;
			case 'P':for(j=0;j<L;j++)if(M[j]<58)M[j]=M[j]==48?57:M[j]-1;break;
			case 'M':for(j=0;j<L;j++) if(M[j]<58)M[j]=M[j]==57?48:M[j]+1;break;
			}
		}
		puts(M);
	}
	return 0;
}