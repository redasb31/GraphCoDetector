#include <stdio.h>

int main(void)
{
        int a,b,c,d,max,min;
        scanf("%d%d%d%d",&a,&b,&c,&d);

        if(a>c)max=a;
        else min=c;
        if(b<d)min=b;
        else min=d;
        if(min>=max)printf("%d\n",min-max);
        else printf("0\n");
        return 0;
}
