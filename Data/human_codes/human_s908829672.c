#include <stdio.h>
 
int main(void)
{
    int pri;
    int cou;
    int kouka[6] = {500, 100, 50, 10, 5, 1};
    int i;
         
    while (1){
        scanf("%d", &pri);
         
        if (pri == 0){
            break;
        }
         
        pri = 1000 - pri;
        cou = i = 0;
        while (pri){
			cou += pri / kouka[i];
			pri -= kouka[i] * (pri / kouka[i]);
			i++;
        }
        printf("%d\n", cou);
    }
     
    return (0);
}