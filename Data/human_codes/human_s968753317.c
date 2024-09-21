#include <stdio.h>

int main() {
    unsigned int a, b;

    scanf("%i%i", &a, &b);

    if(a > b){
        printf("GREATER\n");
    }else if(a < b){
        printf("LESS\n");
    }else{
        printf("EQUAL\n");
    }
    return 0;
}