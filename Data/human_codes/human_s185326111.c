#include <stdio.h>
#include <math.h>

int main(void) {
    int bus_stop[15] = {0,1,2,3,4,5,6,7,8,9,5,4,3,2,1};
    int start, end, spin, n_spin;
    int num, i, j, idx1, idx2;
    
    scanf("%d", &num);
    
    while(num--) {
    
        scanf("%d %d", &start, &end);
        
        for(j = 0; j < 10; j++) {
            if(bus_stop[j] == start) {
                idx1 = j;
            }
            if(bus_stop[j] == end) {
                idx2 = j;
            }
        }

        spin = (idx1 + 1) + (15 - idx2);
        n_spin = fabs(idx2 - idx1) + 1;

        if(n_spin < spin) {
            if(start > end) {
                for(i = idx1; i >= idx2; i--) {
                    printf("%d", bus_stop[i]);
                    if(i == idx2)
                        putchar('\n');
                    else
                        putchar(' ');
                }
            }
            else if(start < end) {
                for(i = idx1; i <= idx2; i++) {
                    printf("%d", bus_stop[i]);
                    if(i == idx2)
                        putchar('\n');
                    else
                        putchar(' ');
                }
            }
        } else if(spin < n_spin) {
            for(i = idx1; i >= 0; i--) {
                printf("%d", bus_stop[i]);
                if(i == idx2)
                    putchar('\n');
                else
                    putchar(' ');
            }
            for(i = 14; i >= idx2; i--) {
                printf("%d", bus_stop[i]);
                if(i == idx2)
                    putchar('\n');
                else
                    putchar(' ');
            }
        }
    }
    
    return(0);
}