// AOJ Volume 0 Problem 0052

#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    int n_2, n_5;
    int i, j;

    while (1){
        scanf("%d", &n);
        if (n == 0){
            break;
        }
        
        n_2 = n_5 = 0;
        for (i = 1; i <= n; i++){
            j = i;
            while (j % 5 == 0){
                j /= 5;
                n_5++;
            }
            while (j % 2 == 0){
                j /= 2;
                n_2++;
            }
        }
        if (n_2 < n_5){
            printf("%d\n", n_2);
        }
        else {
            printf("%d\n", n_5);
        }
    }

	return (0);
}