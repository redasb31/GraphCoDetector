#include <stdio.h>
#define MOD 1000000007

int main()
{
    int n, i;
    char s1[60], s2[60];
    unsigned long int p = 3;

    scanf("%d", &n);
    scanf("%s", s1);
    scanf("%s", s2);
    if (s1[0] != s2[0])
        p *= 2;
    for (i = 0; i < n - 1; i++)
    {
        if (s1[i] == s2[i])
        {
            p = (p * 2) % MOD;
        }
        else
        {
            if (s1[i + 1] != s2[i + 1] && s1[i] != s1[i + 1])
            {
                p = (p * 3) % MOD;
            }
        }
        //printf("%d\n",p);
    }
    printf("%d", p);
    return (0);
}