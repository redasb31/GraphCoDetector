#include <stdio.h>
#include <stdlib.h>
 
typedef struct _card {
        char mark;
        int number;
} Card;
 
int main(){
    //Card *sp;
    Card sp[52];
    int i, n, tempint, j, k, l;
    char tempstr;
    char checkmark[3];
 
    checkmark[0] = 'S';
    checkmark[1] = 'H';
    checkmark[2] = 'C';
    checkmark[3] = 'D';
 
    scanf("%d", &n);
 
    //sp = (Card *) malloc(sizeof(Card) * n);
    n = 52;
    for(i=0;i<n;i++){
            scanf("%c %d\n",sp[i].mark,sp[i].number);
    }
     
    for(j = 0; j < 4; j++){
        for(k = 1; k <= 13; k++){
            for(l = 0; l < n; l++){
                if(checkmark[j] == sp[l].mark && k == sp[l].number){
                    break;
                }
                if(l == n){
                    printf("%c %d\n",checkmark[j], k);
                }
            }
        }
    }
    free(sp);
    return 0;
}