#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, W;
int w[110];
int v[110];

int dp[110][330][100];
//int dp[110][330];

/*
int search_max(int now, int maxnum, int weight, int id) {
  if (dp[now][id] != -1) {
     return dp[now][id];
   }

  if (now == maxnum) {
    if (weight < w[now]) {
      return dp[now][id] = 0;
      // return 0;
    } else {
      return dp[now][id] = v[now];
      // return v[now];
    }
  }

  else {
    int tempin, tempout, tempid;
    if (w[now] <= weight) {
      tempin = search_max(now + 1, maxnum, weight - w[now], id+w[now]-w[0]+1) + v[now];
      
    } else {
      tempin = -1;
    }
    tempout = search_max(now + 1, maxnum, weight, id);
    // printf("num:%d in:%d out:%d\n", now, tempin, tempout);
    if (tempin > tempout) {
      // printf("%d, %d\n", now, tempin);
      return dp[now][id] = tempin;
      // return tempin;
    } else {
      // printf("%d, %d\n", now, tempout);
      return dp[now][id] = tempout;
      // return tempout;
    }
  }
}
*/


int search_max(int now, int maxnum, int weight, int id, int count) {
  if (dp[now][id][count] != -1) {
     return dp[now][id][count];
   }

  if (now == maxnum) {
    if (weight < w[now]) {
      return dp[now][id][count] = 0;
      // return 0;
    } else {
      return dp[now][id][count] = v[now];
      // return v[now];
    }
  }

  else {
    int tempin, tempout, tempid, tempcount;
    if (w[now] <= weight) {
      tempid =id + w[now] - w[0]+1;
      tempcount = count + 1;
      tempin = search_max(now + 1, maxnum, weight - w[now], tempid, tempcount) + v[now];
      
    } else {
      tempin = -1;
    }
    tempout = search_max(now + 1, maxnum, weight, id, count);
    // printf("num:%d in:%d out:%d\n", now, tempin, tempout);
    if (tempin > tempout) {
      // printf("%d, %d\n", now, tempin);
      return dp[now][id][count] = tempin;
      // return tempin;
    } else {
      // printf("%d, %d\n", now, tempout);
      return dp[now][id][count] = tempout;
      // return tempout;
    }
  }
}


/*
int search(const int i, const int n, const int sum_v, const int sum_w)
{
  if (i == n) {
    return sum_v;
  }

  x[i] = 0;
  const double v0 = search(i + 1, n, sum_v, sum_w);

  x[i] = 1;
  const double v1 = search(i + 1, n, sum_v + v[i], sum_w + w[i]);

  return (v0 > v1) ? v0 : v1;
}
*/
/*
void solve_dp2() {
  for (int j = 0; j <= W; j++) {
    dp[n][j] = 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= W; j++) {
      if (j < w[i])
        dp[i][j] = dp[i + 1][j];
      else
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
    }
  }
  cout << dp[0][W] << endl;
}
*/

int main() {
  int i, j, l;
  int ans;

/*
  for (i = 0; i < 110;i++){
    for (j = 0; j < 330;j++){
      dp[i][j] = -1;
    } }
    */
  
    for (i = 0; i < 110;i++){
    for (j = 0; j < 330;j++){
      for (l = 0; l < 100; l++) {
        dp[i][j][l] = -1;
      }
    } }


  scanf("%d %d", &N, &W);
  for (i = 0; i < N; i++) {
    scanf("%d %d", &w[i], &v[i]);
  }

  ans = search_max(0, N - 1, W, 0, 0);
  //ans = search_max(0, N - 1, W, 0);
  printf("%d", ans);

  return 0;
}