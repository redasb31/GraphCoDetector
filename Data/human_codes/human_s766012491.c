#include<stdio.h>
#include<string.h>


int main()
{
	int len,flag=0;
	char str[1025] = { 0 };

	
	while (scanf("%[^ ,.]%*[ ,.]", str)!=EOF)
	{
		len = strlen(str);
		
		if (len > 2 && len < 7)
		{
			if (flag)
			{
				printf(" ");
			}
			printf("%s", str);
			flag = 1;
		}
	}
	printf("\n");

	return 0;
}
