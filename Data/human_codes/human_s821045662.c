#include<stdio.h>

int main()
{
    char s[16];
    int y,m,d;

    scanf("%04d/%02d/%02d",&y,&m,&d);

    if((10000*y+100*m+d-20190430)>=0) printf("TBD");
    else printf("Heisei");
    return 0;
}
