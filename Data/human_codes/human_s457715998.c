#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<limits.h>
#define MAX 202
int max(int a,int b){
    if(a>b) return a;
    else return b;
}

int main(){
    int N;
    int a[MAX],b[MAX],c[MAX],d[MAX];
    bool red[MAX][MAX];
    memset(red,false,sizeof(red));
    bool blue[MAX][MAX];
    memset(blue,false,sizeof(blue));
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d %d",a+i,b+i);
        red[a[i]][b[i]]=true;
    }
    for(int i=1;i<=N;i++){
        scanf("%d %d",c+i,d+i);
        blue[c[i]][b[i]]=true;
    }
    int red_num[MAX][MAX],blue_num[MAX][MAX];
    for(int i=0;i<=2*N;i++)
        red_num[i][0] = red_num[0][i] = blue_num[i][0] = blue_num[0][i] = 0;        
    for(int i=1;i<=2*N;i++){
        for(int j=1;j<=2*N;j++){
            red_num[i][j] += max(red_num[i-1][j],red_num[i][j-1])+((red[i][j])?1:0);
            blue_num[i][j] += max(blue_num[i-1][j],blue_num[i][j-1])+((blue[i][j])?1:0); 
        }
    }
    int DP[MAX][MAX];
    memset(DP,0,sizeof(DP));
    for(int i=1;i<=2*N;i++){
        for(int j=1;j<=2*N;j++){
            DP[i][j] = max(DP[i-1][j],DP[i][j-1]) + (((blue_num[i][j]>=red_num[i][j]) && blue[i][j])?1:0);
        }
    }
    printf("%d",DP[2*N][2*N]);
}
