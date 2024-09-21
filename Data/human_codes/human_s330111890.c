#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char s[51];
    int len,i,haveA=0,haveKIH=0,haveB=0,haveR=0;
    scanf("%s",s);
    len=strlen(s);
    if(len>10)
    {
        printf("NO");
        return 0;
    }
    for(i=0;i<len;i++)
    {
        if(haveKIH==1&&haveB==1&&haveR==1&&haveA==1)
        {
            printf("NO");
            return 0;
        }
        if(s[i]=='A')
        {
            if(haveA==0) haveA=1;
            else
            {
                printf("NO");
                return 0;
            }
        }
        else
        {
            if(s[i]=='K'&&s[i+1]=='I'&&s[i+2]=='H')
            {
                haveA=0;
                haveKIH=1;
                i+=2;
            }
            else
            {
                if(haveKIH==1)
                {
                    if(s[i]=='B')
                    {
                        haveA=0;
                        haveB=1;
                    }
                    else if(s[i]=='R'&&haveB==1)
                    {
                        haveR=1;
                        haveA=0;
                    }
                }
                else
                {
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    printf("YES");
    return 0;
}


