#include <stdio.h>
int a,b;
int kouzi[17][17]={0,};
int memo[17][17];

int keiro(int i,int j){
    if(i>a || j>b || kouzi[i][j])
        return 0;
    if(i==a&&j==b)
        return 1;
    if(memo[i][j])
        return memo[i][j];
    else
        return memo[i][j]=keiro(i+1,j)+keiro(i,j+1);
}
main(){
    int i;
    int t,t2;
    int n;
    while(scanf("%d %d",&a,&b)!=EOF){
        if(a==0)
            break;
        scanf("%d",&n);
        for(i=0;i<17*17;i++)
            kouzi[0][i]=memo[0][i]=0;
        for(i=0;i<n;i++){
            scanf("%d %d",&t,&t2);
            kouzi[t][t2]=1;
        }
        printf("%d\n",keiro(1,1));
    }
    return 0;
}