#include <stdio.h>

int main(void){
    int i,j,n,tmp1,tmp2,c;

    scanf("%d",&n);
    for(i=3;i<=n;i++){
        if(i % 3 == 0){
            printf(" %d\n",i);
        }
        else{
            tmp1 = i;
            tmp2 = i;
            while(tmp1 != 0){
                tmp1 = tmp1 / 10;
                c += 1;
            }
            for(j = 0;j<c;j++){
                if(tmp2 % 10 == 3){
                    printf(" %d\n",i);
                    break;
                }
                else{
                    tmp2 = tmp2 / 10;
                }
            }
        }
    }
    return(0);
}