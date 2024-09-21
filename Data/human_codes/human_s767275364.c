#include <stdio.h>
int main(void){
    int a,b,c,d,e,f,g,i;
    e=0,f=0,g=0;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        e=a+b+c+d;
        g=e/60;
        f=e%60;
        printf("%d\n%d\n",g,f);

return 0;
}