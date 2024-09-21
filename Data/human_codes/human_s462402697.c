#include<stdio.h>

int main(){
    int n,i=0,j;
    int b[10];
    char alp[26] = "abcdefghijklmnopqrstuvwxyz";
    scanf("%d",&n);

    for (i = 0; n > 0; i++) {
        n--;
        b[i] = n % 26;
        n = n / 26;
    }
    //j = i;
    //while (j > 0) printf("%d ",b[--j]);
    while (i > 0) printf("%c",alp[b[--i]]);
    //printf("%c",alp[b[--i]]);
    putchar('\n');
    //printf("%d\n",n);
    return 0;
}