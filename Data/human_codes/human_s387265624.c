#include <stdio.h>

int main()
{
    int arr[31] = {};
    int a;
    int i;

    for (i = 0; i < 28; i++) {
        scanf("%d", &a);

        arr[a] = 1;
    }

    for (i = 1; i <= 30; i++) {
        if (arr[i] == 0) {
            printf("%d\n", i);
        }
    }
    

    return 0;
}

