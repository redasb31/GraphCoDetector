#include<stdio.h>
#include<string.h>
int main(void)
{
    int i,j,k,n,x;
    char s[2000],p[2000],a[30]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    scanf("%d",&x);
    scanf("%s",s);
    n = strlen(s);
    for(i=0;i<n;i++)
    {
        for(j=0;j<26;j++)
        {
            if(s[i] == a[j])
                p[i] = a[(j+x)%26];
        }
    }
    printf("%s",p);
    return 0;
}