#include<stdio.h>
#include<string.h>
int main(void){
    int i,n,a,b;
    char s[101];
    gets(s);
    a=strlen(s);
    b=a-2;
    printf("%c%d%c",s[0],b,s[a-1]);
    return 0;
}