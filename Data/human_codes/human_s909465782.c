#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int *l = malloc(sizeof(int) * n);
    for (int i = 0; i < n;i++){
        scanf("%d", &l[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n - 2;i++){
        for (int j = i + 1; j < n - 1; j++){
            for (int k = j + 1; k < n; k++){
                if((l[i]+l[j]>l[k])&&(l[j]+l[k]>l[i])&&(l[k]+l[i]>l[j])&&(l[i]!=l[j])&&(l[j]!=l[k])&&(l[k]!=l[i])){
                    cnt++;
                }
            }
        }
    }
    printf("%d", cnt);
    return 0;
}