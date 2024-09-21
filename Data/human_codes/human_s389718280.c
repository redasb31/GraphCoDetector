#include <stdio.h>
#include <math.h>
 
#define N 4
 
int search(int board[N][N], int min, int limit, int r_0, int c_0, char mv);
  
int search(int board[N][N], int min, int limit, int r_0, int c_0, char mv)
{
  int md_c[4];
  int op[4], num[4];
  int res[4];
  int i;
  char dir[5] = "nswe";
 
  if (min == 0) return 0;
 
  for (i = 0; i < 4; i++) {
    md_c[i] = min;
    res[i] = -1;
  }
  op[0] = r_0-1;
  op[1] = r_0+1;
  op[2] = c_0-1;
  op[3] = c_0+1;
 
  if (op[0] >= 0) {
    if (mv != 's') {
      num[0] = board[op[0]][c_0];
      md_c[0] -= (int)fabs((num[0]-1)/N - op[0]);
      md_c[0] += (int)fabs((num[0]-1)/N - r_0);
    }
  }
  if (op[1] <= N-1) {
    if (mv != 'n') {
      num[1] = board[op[1]][c_0];
      md_c[1] -= (int)fabs((num[1]-1)/N - op[1]);
      md_c[1] += (int)fabs((num[1]-1)/N - r_0);
    }
  }
  if (op[2] >= 0) {
    if (mv != 'e') {
      num[2] = board[r_0][op[2]];
      md_c[2] -= (int)fabs((num[2]-1)%N - op[2]);
      md_c[2] += (int)fabs((num[2]-1)%N - c_0);
    }
  }
  if (op[3] <= N-1) {
    if (mv != 'w') {
      num[3] = board[r_0][op[3]];
      md_c[3] -= (int)fabs((num[3]-1)%N - op[3]);
      md_c[3] += (int)fabs((num[3]-1)%N - c_0);
    }
  }
 
  for (i = 0; i < 4; i++) {
    if (md_c[i] - min == -1) {
      if (i / 2 == 0) {
    board[op[i]][c_0] = 0;
    board[r_0][c_0] = num[i];
    res[i] = search(board, md_c[i], limit-1, op[i], c_0, dir[i]);
    if (res[i] == -1) {
      board[op[i]][c_0] = num[i];
          board[r_0][c_0] = 0;
    } else res[i]++;
      } else {
    board[r_0][op[i]] = 0;
    board[r_0][c_0] = num[i];
    res[i] = search(board, md_c[i], limit-1, r_0, op[i], dir[i]);
    if (res[i] == -1) {
          board[r_0][op[i]] = num[i];
          board[r_0][c_0] = 0;
        } else res[i]++;
      }
    }
 
    if (res[i] != -1) break;
  }
 
  for (i = 0; i < 4; i++) {
    if (md_c[i] - min == 1) {
      if (md_c[i] <= limit - 1) {
    if (i / 2 == 0) {
      board[op[i]][c_0] = 0;
      board[r_0][c_0] = num[i];
      res[i] = search(board, md_c[i], limit-1, op[i], c_0, dir[i]);
      if (res[i] == -1) {
        board[op[i]][c_0] = num[i];
        board[r_0][c_0] = 0;
      } else res[i]++;
    } else {
      board[r_0][op[i]] = 0;
      board[r_0][c_0] = num[i];
      res[i] = search(board, md_c[i], limit-1, r_0, op[i], dir[i]);
      if (res[i] == -1) {
        board[r_0][op[i]] = num[i];
        board[r_0][c_0] = 0;
      } else res[i]++;
    }
      } else res[i] = -1;
    }
  }
 
  if (res[0] == -1 && res[1] == -1 && res[2] == -1 && res[3] == -1) return -1;
  else if (res[0] != -1) return res[0];
  else if (res[1] != -1) return res[1];
  else if (res[2] != -1) return res[2];
  else return res[3];
}


int main(int argc, char *argv[])
{
  int board[N][N];
  int md;
  int i, j, r, c, r_0, c_0, found;
  int res;
 
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) scanf("%d", &board[i][j]);
  }
 
  md = 0;
  for (i = 0; i < N * N; i++) {
    found = 0;
    for (r = 0; r < N; r++) {
      for (c = 0; c < N; c++) {
    if (board[r][c] == i) {
      if (i == 0) {
        r_0 = r;
        c_0 = c;
      } else md += (int)fabs((i-1)/N - r) + (int)fabs((i-1)%N - c);
      found = 1;
      break;
    }
      }
      if (found == 1) break;
    }
  }
 
  for (i = 0; ; i += 2) {
    if ((r_0 + c_0) % 2 == 0) {
      if (md % 2 == 0) res = search(board, md, md+i, r_0, c_0, 'c');
      else res = search(board, md, md+i+1, r_0, c_0, 'c');
    } else {
      if (md % 2 == 0) res = search(board, md, md+i+1, r_0, c_0, 'c');
      else res = search(board, md, md+i, r_0, c_0, 'c');
    }
 
    if (res != -1) break;
  }
 
  printf("%d\n", res);
 
  return 0;
}
 