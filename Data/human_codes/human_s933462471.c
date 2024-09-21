#include <stdio.h>

int main() {
    int i, j, k;
    int people, foods;
    int temp, count = 0;
    int klist[30] = {0};
    int chklist[30] = {0};
    int AK[30][30] = {0};
    
    scanf("%d",&people);
    scanf("%d",&foods);
    
    for (i = 0; i < people; i++) {
        scanf("%d",&klist[i]);
        for (j = 0; j < klist[i]; j++) {
            scanf("%d",&AK[i][j]);
        }
    }

    for (k = 1; k <= foods; k++) {
        temp = 0;
        for (i = 0; i < people; i++) {
            for (j = 0; j < klist[i]; j++) {
                if(k == AK[i][j]) {
                    chklist[k] += 1;
                }
            }
        }
        if (chklist[k] == people) {
            count += 1;
        }
    }
    
    printf("%d",count);
    
    return 0;
}