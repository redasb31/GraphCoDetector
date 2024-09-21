#include <stdio.h>
#define min(x, y) ((x)>(y) ? (y) : (x))

int n, notSit[502][502] = {0};
long oneans;

void dfs(int seki[][502], int nowr, int nowc, long count){
  if(nowr==1 || nowr==n || nowc==1 || nowc==n){
    oneans = min(oneans, count);
    return;
  }

  int flag = 1;
  for(int i=-1; i<=1; i+=2){
    if(seki[nowr+i][nowc] == 1)  continue;
    flag = 0;
    seki[nowr+i][nowc] = 1;
    dfs(seki, nowr+i, nowc, count+(notSit[nowr+i][nowc]==0));
    seki[nowr+i][nowc] = 0;
  }
  for(int i=-1; i<=1; i+=2){
    if(seki[nowr][nowc+i] == 1)  continue;
    flag = 0;
    seki[nowr][nowc+i] = 1;
    dfs(seki, nowr, nowc+i, count+(notSit[nowr][nowc+i]==0));
    seki[nowr][nowc+i] = 0;
  }
  if(flag)  return;
}

int main(){
  scanf("%d", &n);
  int jun[2510] = {0};
  for(int i=1; i<=n*n; i++)  scanf("%d", jun+i);
  long ans = 0;
  for(int i=1; i<=n*n; i++){
    int row = (jun[i]-1)/n + 1;
    int column = (jun[i]-1)%n + 1;
    int seki[502][502] = {0};
    seki[row][column] = 1;
    oneans = 2222222222222222;
    dfs(seki, row, column, 0);
    ans += oneans;
    notSit[row][column] = 1;
  }
  printf("%ld\n", ans);
  return 0;
}


  
