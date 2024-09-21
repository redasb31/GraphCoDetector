#include<stdio.h>
#include<string.h>

int main(){

char S[3];
for (int i = 0; i < 3; i++)
{
    scanf("%c",&S[i]);
}

if (S[0]=='R'){
    if (S[1]=='R'){
        if (S[2]=='R')
        {
            puts("3");
        }else{
            puts("2");
        }
    }else{
        puts("1");
    }
}else{
    if (S[1]=='R'){
        if (S[2]=='R')
        {
            puts("2");
        }else
        {
            puts("1");
        }
    }else{
        if (S[2]=='R')
        {
            puts("1");
        }else
        {
            puts("0");
        }
    }
}

return 0;

}