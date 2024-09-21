#include <stdio.h>
#include <string.h>

int main(){

    char a[200000];
    char b[200000];

    int d = 0;


    scanf("%s",a);
    scanf("%s",b);



    for(int i = 0;i < strlen(a); ++i){
        if(a[i] == b[i])
            ++d;
    }
    printf("%d\n",strlen(a)- d);



    return 0;
}