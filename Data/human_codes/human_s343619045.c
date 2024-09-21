#include<stdio.h>
int main(void){
    int i,x,y;
    char S[3];
    x=700;

    for(i=0; i<3; i++){
        scanf("%c",&S[i]);

        if(S[i]=='o'){
            y+=100;
        }

        else{
            x=x;
        }   
    }
    printf("%d\n",x+y);
    return 0;
}