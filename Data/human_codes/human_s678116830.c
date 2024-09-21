#include <stdio.h>

int uruu (int i){
    if (i % 400 == 0) {
        return 1;
    }
    else if (i % 100 == 0){
        return 0;
    }
    else if (i % 4 == 0){
        return 1;
    }
    else {
        return 0;
    }
    
}
int main(){
    int a, b, i;
    int counter;
    while (1) {
        counter = 0;
        scanf("%d %d",&a, &b);
        if (a == 0 && b == 0) {
            break;
        }
        for (i = a; i <= b; i++) {
            if (uruu (i) == 1) {
                printf("%d\n",i);
                counter++;
            }
        }
        if (counter == 0) {
            printf("NA\n");
        }
        printf("\n");
    }
    return 0;
}