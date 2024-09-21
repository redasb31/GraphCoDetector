#include <stdio.h>
#include <string.h>

int main(void)
{
    int i;
    int te[6];
    int freq[4];
    
    while (1){
        scanf("%d", &te[1]);
        if (te[1] == 0){
            break;
        }
        
        for (i = 2; i <= 5; i++){
            scanf("%d", &te[i]);
        }
        
        memset(freq, 0, sizeof(freq));
        
        for (i = 1; i <= 5; i++){
            freq[te[i]]++;
        }
        
        if (freq[1] * freq[2] * freq[3] != 0){
            printf("3\n3\n3\n3\n3\n");
            continue;
        }
        if (freq[1] + freq[2] == 0 || freq[2] + freq[3] == 0 || freq[3] + freq[1] == 0){
            printf("3\n3\n3\n3\n3\n");
            continue;
        }
        
        if (freq[1] == 0){
            for (i = 1; i <= 5; i++){
                if (te[i] == 2){
                    printf("1\n");
                }
                else {
                    printf("2\n");
                }
            }
        }
        else if (freq[2] == 0){
            for (i = 1; i <= 5; i++){
                if (te[i] == 1){
                    printf("2\n");
                }
                else {
                    printf("1\n");
                }
            }
        }
        else if (freq[3] == 0){
            for (i = 1; i <= 5; i++){
                if (te[i] == 1){
                    printf("1\n");
                }
                else {
                    printf("2\n");
                }
            }
        }
    }
    return (0);
}

    