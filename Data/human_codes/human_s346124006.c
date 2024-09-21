#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define rep(i,n) for(i=0;i<n;i++)
#define PI 3.14159265358979323846264338327950L
int main(){
    int x,y,n,m;
    scanf("%d%d",&n,&m);
    char a[60][60],b[60][60];
    rep(y,n) rep(x,n) scanf("%c",&a[y][x]);
    rep(y,m) rep(x,m) scanf("%c",&b[y][x]);
    int addx,addy,match=1;
    rep(addy,n-m+1){
        rep(addx,n-m+1){
            if(addx>=n-m+1||addy>=n-m+1) continue;
            rep(y,m){
                rep(x,m){
                    if(a[y+addy][x+addx]!=b[y][x]) match=0;
                }
            }
            if(match==1){
                printf("Yes");
                return 0;
            }
        }
    }
    printf("No");
    return 0;
}