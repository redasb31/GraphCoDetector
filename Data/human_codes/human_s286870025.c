#include<stdio.h>
#include<ctype.h>
#include<string.h>
int i,j;
char S[105],T[105],C;
void U()
{
	for(i=j=0;S[i];i++)
	{
		if(S[i]=='_'&&S[i+1]>'Z')S[i+1]-=0x20;
		else T[j++]=S[i];
	}
}
void D()
{
	for(i=j=0;S[i];i++)
	{
		if(i&&S[i]<'a'&&S[i]!='_'){T[j++]='_';T[j++]=tolower(S[i]);}
		else T[j++]=tolower(S[i]);
	}
}

int main()
{
	for(;scanf("%s %c\n",S,&C),C!='X';puts(T))
	{
		memset(T,0,sizeof(T));
		switch(C)
		{
		case'U':U();T[0]=toupper(T[0]);break;
		case'L':U();T[0]=tolower(T[0]);break;
		default:D();
		}
	}
	return 0;
}