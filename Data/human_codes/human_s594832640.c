#include<stdio.h>
typedef struct{
    int won;
    int lost;
}Team;
Team team[9];
int n,m;
int cnt;
int map[9][9];
void init(){
    for(int i=0;i<n;i++){
        team[i].won=team[i].lost=0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)
                map[i][j]=1;
            else
                map[i][j]=0;
        }
    }
}
void rec(int y, int x){
    if(x==n){
        y++; x=y+1;
    }
    
    
    if(team[y].won>(n/2));
    else if(team[y].lost>(n/2));
    else if(y==n-2 && x==n-1){
        cnt++;
    }
    else{
        if(map[y][x]!=0){
            rec(y,x+1);
        }
        else{
            if(team[y].won<(n/2)){
                team[y].won++;
                team[x].lost++;
                map[y][x]=map[x][y]=1;
                rec(y,x+1);
                map[y][x]=map[x][y]=0;
                team[y].won--;
                team[x].lost--;
            }
            
            if(team[y].lost<(n/2)){
                team[y].lost++;
                team[x].won++;
                map[y][x]=map[x][y]=1;
                rec(y,x+1);
                map[y][x]=map[x][y]=0;
                team[y].lost--;
                team[x].won--;
            }
        }
    }
}
int main(void){
    while(1){
        scanf("%d",&n); if(n==0) break;
        init();
        scanf("%d",&m);
        for(int i=0; i<m; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            x--; y--;
            map[x][y]=1;
            map[y][x]=1;
            team[x].won++; team[y].lost++;
        }
        cnt=0;
        rec(0,0);
        printf("%d\n",cnt);
    }
}

