// AOJ 1338: Clock Hands
// 2017.12.7 bal4u@uu

#include <stdio.h>

long long gcd(long long a, long long b)
{
	long long r;
	while (b != 0) r = a % b, a = b, b = r;
	return a;
}

int main()
{
    int H, h, m, s;
	long long c3600, ha, ma, sa, a1, a2, g, d, n;

    while (scanf("%d%d%d%d", &H, &h, &m, &s) && H > 0) {
        d = 119*H - 1;
		c3600 = 3600*H*d;
        n = s * d;
        while (1) {
            ha = (60 * h + m) * 60*d + n;
            ma = 60 * H * m * d + n * H;
            sa = 60 * H * n;
            ma = (ma - ha) % c3600;
            sa = (sa - ha) % c3600;
            if (ma < 0) ma += c3600;
            if (sa < 0) sa += c3600;
            if (ma != 0) {
                if (ma < sa) a1 = c3600 - sa, a2 = sa - ma;
                else         a1 = sa, a2 = ma - sa;
                if (a1 == a2) break;
            }
            n++;
            if (n == 60 * d) m++, n = 0;
            if (m == 60) m = 0, h++;
            if (h == H) h = 0;
        }
        g = gcd(n, d);
        printf("%d %d %d %d\n", h, m, (int)(n/g), (int)(d/g));
    }
}