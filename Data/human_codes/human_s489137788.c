#include <stdio.h>
#include <string.h>


int main(void)
{
    char a[10], b[10], e[10];
    int c, d;
    
    printf("\n");
    scanf("%s", a);
    
    printf("\n");
    scanf("%s", b);
    
    printf("\n");
    scanf("%d", &c);
    
    printf("\n");
    scanf("%d", &d);
    
    printf("\n");
    scanf("%s", e);
    
    /*
    int ret= strcmp(a[10], e[10]);
    
    int ret2= strcmp(b[10], e[10]);
    
     */
    if(!strcmp(a, e))
    {
        printf("%d %d", c-1, d);
    }
    else if(!strcmp(b, e))
    {
        printf("%d %d", c, d-1);
    }
    
    return 0;
}
