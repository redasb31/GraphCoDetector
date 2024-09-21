#include<stdio.h>
int main(void){
    int a[3][3],n;
    for(int i=0;3>i;++i){
        for(int j=0;3>i;++i)
        scanf("%d",&a[i][j]);
    }
    scanf("%d",&n);
    int b[n];
    for(int i=0;n>i;++i){
        scanf("%d",b[i]);
    }
    for(int k=0;n>k;++k){
        for(int i=0;3>i;++i){
            for(int j=0;3>j;++j){
                if(b[k]==a[i][j])
                b[k]=0;
            }
        }
    }
    for(int i=0;3>i;++i){
        if(a[0][i]==a[1][i]&&a[1][i]==a[2][i])
        printf("Yes");
    }
    for(int i=0;3>i;++i){
        if(a[i][0]==a[i][1]&&a[i][1]==a[i][2])
        printf("Yes");
    }
    if(a[0][0]==a[1][1]&&a[1][1]==a[2][2])
    printf("Yes");
    if(a[0][2]==a[1][1]&&a[1][1]==a[2][0])
    printf("Yes");
    return 0;
}