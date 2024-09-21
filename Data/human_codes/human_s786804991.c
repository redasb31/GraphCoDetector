#include<stdio.h>
int main(void){
    char S[3];
    int sum = 700;
    for(int i = 0; i < 3; i++){
        scanf("%c",&S[i]);
        if(S[i] == 'o') sum += 100;
    }
    printf("%d\n",sum);
    return 0;
}