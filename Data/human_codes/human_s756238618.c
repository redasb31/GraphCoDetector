
#include <stdio.h>
#include <string.h>
#include <math.h>
 
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, m, i, j, x, z;
   
    scanf("%d%d",&n, &m);
    int s[n][2];
    
    for(i=0; i<m; i++)
        for(j=0; j<2; j++)
            scanf("%d", &(s[i][j]) );
    
    z = n-1;
    x = n-m;

    printf("%d\n", z-x);
    
    return 0;
}
