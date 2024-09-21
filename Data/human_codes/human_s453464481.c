#include <stdio.h>
 
int main()
{
    int n, ctr = 0;
    scanf("%d", &n);
    char input[n];
    scanf("%s", input);
    for(int i = 0; i < 1500; i++)
    {
    	int math[3] = {i%10, i/100 ,(i/10)%10};
    	int temp = 0;
    	for(int j = 0; j < n; j++)
    	{
    		if(input[j] == (math[temp] + '0'))
    		{
    			temp++;
			}
			if(temp == 3)
			{
				break;
			}
		}
		if(temp == 3)
		{
			ctr++;
		}
	}
	printf("%d", ctr);
 
    return 0;
}