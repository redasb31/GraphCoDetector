#include<stdio.h>
int main(void){
int road[20][20]={{0}},i,j,t,a,b,tree,tx,ty,ans;
for(;;){
    road[1][1]=1;
    scanf("%d %d",&a,&b);
    if(a==0&&b==0)break;
    scanf("%d",&tree);
    for(t=0;t<tree;t++){
        scanf("%d %d",&tx,&ty);
        road[tx][ty]=-1;
    }
    for(i=1;i<=a;i++){
        for(j=1;j<=b;j++){
            if(road[i][j]==0){
                if(i==1){
                    road[i][j]=road[i][j-1];
                }
                else if(j==1){
                    road[i][j]=road[i-1][j];
                }
                else{
                    if(road[i][j-1]==-1){
                        road[i][j]=road[i-1][j];
                    }
                    else if(road[i-1][j]==-1){
                        road[i][j]=road[i][j-1];
                    }
                    else{
                    road[i][j]=road[i-1][j]+road[i][j-1];
                    }
                }
            }
        }
    }
    printf("%d\n",road[a][b]);
}

return 0;
}