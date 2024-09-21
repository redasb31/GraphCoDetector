#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, a[100000], i, on=0, count=0;
    bool flag = false;
    scanf("%d\n", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    while (n>0) {
        on = a[on] - 1;
        count ++;
        n --;
        if (on == 1) {
            flag = true;
            break;
        }
    }
    if (flag == true) printf("%d\n", count);
    else printf("-1\n");
    return 0;
}
