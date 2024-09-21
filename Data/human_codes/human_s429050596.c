#include<stdio.h>
int main(void){
    int m,f,r,total;
    for(;;){
        scanf("%d%d%d",&m,&f,&r);
        total=m+f;
        if(m==-1&&f==-1)
            break;
        else if(m==-1||f==-1)
            puts("F");
        else if(total>=80)
            puts("A");
        else if(80>total&&total>=65)
            puts("B");
        else if(65>total&&total>=50)
            puts("C");
        else if(50>total&&total>=30){
            if(r>=50)
                puts("C");
            else
                puts("D");
        }
        else
            puts("F");
    }
    return 0;
}