#include <stdio.h>

int main(void){
        char mark;
        char mk[4][2]={"S", "H", "C", "D"};
        int n, i, j, num;
        int trump[4][13]={0};
        do{
                scanf("%d", &n);
        }while(n>52);
        for(i=0;i<n;i++)
                scanf("%c %d", &mark, &num);
        for(i=0;i<n;i++){
                if(mark=='S')
                        trump[0][num-1]=1;
                if(mark=='H')
                        trump[1][num-1]=1;
                if(mark=='C')
                        trump[2][num-1]=1;
                if(mark=='D')
                        trump[3][num-1]=1;
        }
        for(i=0;i<4;i++){
                for(j=0;j<13;j++){
                        if(trump[i][j]==0)
                                printf("%s %d\n", mk[i], j+1);
                }
        }
        return 0;
}