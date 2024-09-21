#include <stdio.h>
#include <stdlib.h>

int n;
int a[100005];
int k;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        if (a[tmp] == 0) {
            k++;
            a[tmp] = 1;
        }
    }

    if (k & 1) {
        printf("%d\n", k);
    }
    else {
        printf("%d\n", k - 1);
    }

    return 0;
}
