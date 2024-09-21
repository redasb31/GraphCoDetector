#include <stdio.h>
#include <math.h>
int main(){
    double a, b, c;
    double x=0;
    double  y=0;
    double z=0;
    scanf("%lf %lf %lf", &a, &b ,&c);
    x = sqrt(a);
    y = sqrt(b);
    z = sqrt(c);
    if(x+y<z) printf("Yes");
    else printf("No");
}