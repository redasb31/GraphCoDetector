#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define N 100000
#define MAX 1000000000000000000

int main (void)
{
    unsigned long long a, b_100;
    double b;
    char s[10];
    int i, dot = 0;

    scanf("%llu %s", &a, s);

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '.') {
            dot = i;
            s[i] = '\0';

            if (s[i + 2] == '\0') {
                s[i + 2] = '0';
                s[i + 3] = '\0';
            }
        }
    }

    if (dot != 0) {
        b_100 = (unsigned long long)(atoi(s) * 100) + atoi(&(s[dot + 1]));
    } else {
        b_100 = (unsigned long long)(atoi(s) * 100);
    }

    printf("%llu", a * b_100 / 100);

    return 0;
}
