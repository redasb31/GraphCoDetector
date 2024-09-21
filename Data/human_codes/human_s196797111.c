#include <stdio.h>
int main()
{
    double ans;
    int h, w, x ,y;
    int j=0;
    scanf("%d%d%d%d", &w, &h, &x, &y);
    ans=(w*h)/2.0;
    if(x+x==w && y+y==h) j=1;
    printf("%.9f %d\n", ans, j);
    return 0;
}
