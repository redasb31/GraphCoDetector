#include <stdio.h>

int main(void)
{
    int i=0,flg=0;
    char c[100];
    
    while(1)
    {i=0;
    if (scanf("%s",c) == EOF)
        break;
        
    while(1)
    {
        if('a'<=c[i]&&c[i]<='z')
        c[i]=c[i]-'a'+'A';
        
        i++;
        if(c[i]==0)
            break;
        
    }
    if(flg==1)
        printf(" ");
        
    printf("%s",c);
        flg=1;
    }
       return 0;
    
}