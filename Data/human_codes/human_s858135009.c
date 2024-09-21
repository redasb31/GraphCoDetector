#include<stdio.h>
char dice[8][5][5];
int MIN(int x,int y){ return x<y?x:y; }
int input()
{
    int i,j;
    for(i=1;i<=6;i++)
    {
        for(j=2;j>=0;j--)
        {
            scanf("%s",dice[i][j]);
            if(i==1&&j==2&&dice[i][j][0]=='#') return 0;
        }
    }
    return 1;
}
int main()
{
    int i,res,flag1,flag2;

    while(input())
    {
        res=10000;

        for(flag1=i=0;i<3;i++) if(dice[1][0][i]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[3][0][i]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,0);
        for(flag1=i=0;i<3;i++) if(dice[1][2][i]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[3][2][i]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,2);
        for(flag1=i=0;i<3;i++) if(dice[1][i][0]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[3][i][0]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,1);
        for(flag1=i=0;i<3;i++) if(dice[1][i][2]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[3][i][2]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,1);

        for(flag1=i=0;i<3;i++) if(dice[2][0][i]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[4][0][i]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,3);
        for(flag1=i=0;i<3;i++) if(dice[2][2][i]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[4][2][i]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,3);
        for(flag1=i=0;i<3;i++) if(dice[2][i][0]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[4][i][2]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,2);
        for(flag1=i=0;i<3;i++) if(dice[2][i][2]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[4][i][0]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,2);

        for(flag1=i=0;i<3;i++) if(dice[5][0][i]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[6][2][i]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,1);
        for(flag1=i=0;i<3;i++) if(dice[5][2][i]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[6][0][i]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,1);
        for(flag1=i=0;i<3;i++) if(dice[5][i][0]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[6][i][0]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,2);
        for(flag1=i=0;i<3;i++) if(dice[5][i][2]=='*') flag1=1;
        for(flag2=i=0;i<3;i++) if(dice[6][i][2]=='*') flag2=1;
        if(flag1&&flag2) res=MIN(res,2);

        printf("%d\n",res);
    }
    return 0;
}