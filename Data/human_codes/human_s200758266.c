#include <stdio.h>

int main()
{
    char c, res;

    scanf("%c", &c);

    switch (c) {
        case 'A':
            res = 'T';
            break;
        case 'T':
            res = 'A';
            break;
        case 'C':
            res = 'G';
            break;
        case 'G':
            res = 'C';
            break;
    }

    printf("%c\n", res);

    return 0;
}
