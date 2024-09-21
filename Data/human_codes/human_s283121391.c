#include<stdio.h>
int main()
{
        long int N,flag;
        scanf("%ld",&N);
        char arr[2*N+2];
        for(int i=0;i<2*N+2;i++)
                scanf("%c",&arr[i]);
        for(int i=0;i<2*N+2;i++){
                if(arr[i]=='Y'){
                        flag=1;
                        break;
                }
        }
        if(flag==1)
                printf("Four\n");
        else
                printf("Three\n");
        return 0;
}
