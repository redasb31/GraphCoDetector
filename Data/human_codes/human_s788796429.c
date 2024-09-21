#include<stdio.h>
#include<string.h>

int main()
{
    char buffer[256];
    int n;
    int i;
    char animal[2][101];
    int taro, hanako, judge;
    taro = 0;
    hanako = 0;
    
    fgets(buffer, 256, stdin);
    sscanf(buffer, "%d", &n);
    for(i=0;i<n;i++)
    {
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%s %s", animal[0], animal[1]);
        judge = strcmp(animal[0], animal[1]);
        if(judge > 0)
        {
            taro+=3;
        }
        else if(judge == 0)
        {
            taro++;
            hanako++;
        }
        else
        {
            
            hanako+=3;
        }
    }
    printf("%d %d\n", taro, hanako);
    
    return(0);
}
