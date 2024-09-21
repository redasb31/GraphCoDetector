#include<stdio.h>
#include<string.h>
int main(void){
    int h,w;
    char in[1000][30][6];
    char c;
    scanf("%d %d",&h,&w);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%s",in[i][j]);
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(strcmp(in[i][j],"snuke")==0){
                c=(char)j+65;
                printf("%c%d\n",c,i+1);
                break;
            }
        }
    }
    return 0;
}
