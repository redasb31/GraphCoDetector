#include <stdio.h>
int main(void){
    int H,W,i,j;
    while(1){
        scanf("%d %d",&H,&W);
        if(H==0&&W==0){
            break;
        }
        for(i=0;i<H;i++){
            for(j=0;j<W;j++){
                if(i==0||j==0||i==H-1||j==W-1){
                    printf("#");
                }
                else{
                    printf(".");
                }
            }
            puts("");
        }
        puts("");
    }
    return 0;
}