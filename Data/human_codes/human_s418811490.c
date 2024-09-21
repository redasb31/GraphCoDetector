#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	int n;
	int c=0;
	char s[55]={};
	const char abc[3]="ABC"; 
	
	scanf("%d",&n);
	scanf("%s",s);
	
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')	c++;
	}
	printf("%d \n",c);
	return 0;
}