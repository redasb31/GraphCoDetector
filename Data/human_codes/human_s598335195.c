#include <stdio.h>
int main()
{
 int N,i,x;
 scanf("%d",&N);
 for (i = 3; i <= N; i++){
        if (i % 3 == 0)
            printf(" %d", i);
        else {
            x = i;
            while (x != 0){
                if (x % 10 == 3){
                    printf(" %d", i);
                    break;
                }
                x=x/ 10;
            }
     }
    }
      
 printf("\n");
 return 0;
}