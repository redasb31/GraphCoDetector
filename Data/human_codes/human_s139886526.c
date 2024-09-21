#include<stdio.h>
#include<math.h>

const int MAX_N = 1000; // nの最大値
const int MAX_W = 1000000000; // Wの最大値
int solve_dp2();

// 入力
int n, W;
int w[MAX_N], v[MAX_N];

// DPテーブル
// dp[i][j]はi番目以降の品物から重さの和がj以下なるように選んだときの価値の和の最大値を表す。
int dp[MAX_N + 1][MAX_W + 1];

int solve_dp2() {
  for (int j = 0; j <= W; j++) {
    dp[n][j] = -1;
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= W; j++) {
      if (j < w[i])
        dp[i][j] = dp[i + 1][j];
      else
        dp[i][j] = fmax(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
    }
  }
  return dp[0][W];
}

int main(){
  int i,a,b;

  scanf("%d%d",&n,&W);

  for (i = 0; i < n; i++){
    scanf("%d%d",&a,&b);
    w[i] = a;
    v[i] = b;
  }
  int result = 0;
  result = solve_dp2();
  printf("%d\n", result);
  return 0;
}
