#include <stdio.h>

int main (int argc, char *argv[]) {
    int i = 2;
    int first = 0;
    int isFound = 0;
    char c;
    c = getchar();
    while (i <= 100 && c != EOF) {
        if (c == 'C') first = 1;
        if (first == 1 && c == 'F') isFound = 1;
        c = getchar();
        i++;
    }
    if (isFound == 1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}