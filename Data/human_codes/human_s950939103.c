#include <stdio.h>
int main(){
    char a;
    scanf("%c", &a);
    if (a >= 'A' && a <= 'Z'){
        printf("A");
    }else{
        printf("a");
    }
    return 0;
    
}