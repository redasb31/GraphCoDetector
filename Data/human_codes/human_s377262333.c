#include<stdio.h>

int main(){
        int a,b,ab;
        int i;

        for(i = 0; i < 7; i++){
                scanf("%d",&a);
                scanf("%d",&b);
                
                ab = b - a;
                ab = abs(ab);

                printf("%d\n",ab);
                 
        }

        return 0;
}