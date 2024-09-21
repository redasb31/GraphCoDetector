#include <stdio.h>
int main(void){
    // Your code here!
    int n, x, y, z, w, i;
    
    scanf("%d", &n);
    
    for(i=1; i<n+1; i++){
        x = i / 1000;
        y = (i - x*1000) / 100;
        z = (i - (x*1000 + y*100)) / 10;
        w = i - (x*1000 + y*100 + z*10);
    
        if(i%3 == 0 || x == 3 || y == 3 || z == 3 || w == 3){
            printf(" %d", i);
        }
    }
    
    printf("\n");
    return 0;
}

