#include<stdio.h>
#include<string.h>
int main()
{
    char S1[10],s2[10],s3[10];
    int i;
    scanf("%s %s %s",&S1,&s2,&s3);

    for(i=0;i<10;i++){
    if('a'<=S1[i] && S1[i]<='z' && 'a'<=s2[i] && s2[i]<='z' && 'a'<=s3[i] && s3[i]<='z'){
       continue;

    }
    }
    S1[0]=S1[0]-32;
    s2[0]=s2[0]-32;
    s3[0]=s3[0]-32;
    printf("%c%c%c",S1[0],s2[0],s3[0]);
    return 0;
}