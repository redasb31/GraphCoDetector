#include <stdio.h>
int main(void){
    int n,x=0,max=0,i;
    char s[100];
    scanf("%d %s",&n,s);
    for(i=0;i<n;i++){
        if(s[i]=='I') x++;
        else x--;
        if(x>max) max=x;
    }
    printf("%d\n",max);
    return 0;
}