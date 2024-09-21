#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int main()
{
    char s[200010],t[200010];
    bool done[3000];

    scanf("%s",s);
    scanf("%s",t);

    for( int i=0;i<strlen(s);i++ ){
        // if( done[t[i]] == false ){
        //     done[t[i]] = true;
            printf("%c\n",t[i]);
            for( int j=i+1;j<strlen(s);j++){
                if( t[i] == t[j] ){
                    if( s[i] != s[j] ){
                        printf("No\n");
                        return 0;
                    }
                }
            }
        // }
    }
    printf("Yes\n");

    return 0;
}