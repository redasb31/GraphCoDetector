#include <stdio.h>

int main() {
    int x,y;

    scanf("%d %d\n", &x, &y);

    while (x != 0 && y != 0) {
        if (x > y)
            printf("%d %d\n", y, x);
        else
            printf("%d %d\n", x, y);

        scanf("%d %d\n", &x, &y);
    }
    
    return 0;
}

