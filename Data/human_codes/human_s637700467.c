#include <string.h>
#include <stdio.h>

int main()
{   int h,w;
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char s[6];
            scanf("%s",s);
            if(strcmp(s,"snuke")==0){
                printf("%c%d",'A'+j,i+1);
                return 0;
            }
        }
    }
    printf("Hello World");

    return 0;
}
