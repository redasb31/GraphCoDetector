#include <stdio.h>
int main(void){
    int a,b,c;
    int i,j,l,m;
    
    scanf("%d\n%d\n%d",&a,&b,&c);
    printf("%d %d %d\n",a,b,15-a-b);
    l=a+b-c;m=15-a-c;
    i=15-a-l;j=a+b-m;
    printf("%d %d %d\n",i,c,j);
    printf("%d %d %d\n",l,15-b-c,m);
    return 0;
}
