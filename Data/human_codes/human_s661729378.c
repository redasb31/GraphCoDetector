#include<stdio.h>
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int i;
    int ans[3] = {};
    int p;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p);
        if (p <= a)ans[0]++;
        else if (p <= b)ans[1]++;
        else ans[2]++;
    }
    printf("%d\n", min(min(ans[0], ans[1]), ans[2]));
    return 0;
}