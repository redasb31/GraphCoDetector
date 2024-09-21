//b.c B-Great Ocean View
#include<stdio.h>
#include<stdbool.h>

int main(void){
    int n;
    int count=0;
    scanf("%d",&n);
    int h[n];
    for(int i=0;i<n;++i){
        scanf("%d",h+i);
    }
    for(int i=0;i<n;++i){
        int x = h[i];
        bool flag = true;
        for(int j=0;j<i;++j){
            if(x<h[j]){
                flag = false;
            }
        }
        if(flag){
            count++;
        }
    }
    printf("%d\n",count);
    return 0;
}