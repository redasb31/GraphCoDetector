#include<stdio.h>
#include<math.h>
int main()
{
    int h, w;
    long d;
    long a[300][300];
    long q;
    long l, r;
    scanf("%d %d %ld", &h, &w, &d);
    int i, j, k;
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            scanf("%ld", &a[i][j]);
    scanf("%ld", &q);
    int n1, n2, m1, m2;
    long ans;
    for (k = 0; k < q; k++)
    {
        scanf("%ld %ld", &l, &r);
        ans = 0;
        for (i = 0; i < h; i++)
            for (j = 0; j < w; j++)
                if (a[i][j] == l)
                {
                    n1 = i;
                    m1 = j;
break;
                }
        while (l != r)
        {
            for(i=0;i<h;i++)
                for(j=0;j<w;j++)
                    if (a[i][j] == (l + d))
                    {
                        n2 = i;
                        m2 = j;
break;
                    }
            ans += (abs(n1 - n2) + abs(m1 - m2));
            n1 = n2;
            m1 = m2;
            l += d;
        }
        printf("%ld\n", ans);
    }
    return 0;
}
