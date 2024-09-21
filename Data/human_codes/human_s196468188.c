#include<stdio.h>
#include<string.h>
int main()
{
	int i,n = 1;
	char s[5][105];
	int len[5],t[5];
	for(i = 1;i <= 3;i++)
	{
		scanf("%s",s[i] + 1);
		len[i] = strlen(s[i] + 1);
		t[i] = 0;
	}
	t[1] = 1;
	while(1)
	{
		if(s[n][t[n]] == 'a')
		{
			t[1]++;
			n = 1;
		}
		else if(s[n][t[n]] == 'b')
		{
			t[2]++;
			n = 2;
		}
		else if(s[n][t[n]] == 'c')
		{
			t[3]++;
			n = 3;
		}
		if(t[n] == len[n] + 1)
		{
			if(n == 1)
				printf("A\n");
			else if(n == 2)
				printf("B\n");
			else if(n == 3)
				printf("C\n");
			break;
		}

	}
	return 0;
}
