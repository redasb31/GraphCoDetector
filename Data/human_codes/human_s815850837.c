#include <stdio.h>
#include <string.h>
#define MOD 1000000007
#define SMAX 2000
#define CMAX 26

int dp[SMAX][SMAX], nearl[CMAX][SMAX], nearr[CMAX][SMAX];
int dfs(int l, int r);
int main(void)
{
  int i, j, slen;
  char str[SMAX+1];
  scanf("%s", str);
  slen = strlen(str);
  for (i = 0; i < CMAX; i++) {
    for (j = 0; j < slen; j++) {
      nearl[i][j] = slen;
      nearr[i][j] = -1;
    }
  }
  for (i = 0; i < slen; i++) nearl[str[i]-'a'][i] = nearr[str[i]-'a'][i] = i;
  for (i = 0; i < CMAX; i++) {
    for (j = slen - 2; j >= 0; j--) {
      if (nearl[i][j] > nearl[i][j+1]) nearl[i][j] = nearl[i][j+1];
    }
    for (j = 1; j < slen; j++) {
      if (nearr[i][j] < nearr[i][j-1]) nearr[i][j] = nearr[i][j-1];
    }
  }
  memset(dp, -1, sizeof(dp));
  printf("%d\n", dfs(0, slen - 1));
}

int dfs(int l, int r)
{
  int i;
  long long res = 0;
  if (~dp[l][r]) return dp[l][r];
  for (i = 0; i < CMAX; i++) {
    if (nearl[i][l] <= nearr[i][r]) res++;
    if (nearl[i][l] < nearr[i][r]) res += dfs(nearl[i][l] + 1, nearr[i][r] - 1) + 1;
  }
  return dp[l][r] = res % MOD;
}
