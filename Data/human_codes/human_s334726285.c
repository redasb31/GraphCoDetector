#include<stdio.h>
#define p(a) putchar(a);break
char S[3];

int main()
{
	for(;~scanf("%2c",S);)
	{
		if(S[0]=='0'&&S[1]=='U')printf("nn");
		else
		{
			switch(S[0]-'0')
			{
			case 1:break;
			case 2:p('k');
			case 3:p('s');
			case 4:p('t');
			case 5:p('n');
			case 6:p('h');
			case 7:p('m');
			case 8:p('y');
			case 9:p('r');
			default:p('w');
			}
			switch(S[1])
			{
			case 'T':p('a');
			case 'L':p('i');
			case 'U':p('u');
			case 'R':p('e');
			default:p('o');
			}
		}
	}
	puts("");
	return 0;
}