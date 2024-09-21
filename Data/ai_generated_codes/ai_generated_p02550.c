// Problem: A^2 mod M sequence
// Contest: AtCoder - AtCoder Beginner Contest 157
// URL: https://atcoder.jp/contests/abc157/tasks/abc157_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://github.com/coder-yujun/cp-editor)

#include <bits/stdc++.h>
using namespace std;

long long N, X, M;

int main() {
  cin >> N >> X >> M;

  long long sum = 0;
  long long current = X;
  for (long long i = 0; i < N; i++) {
    sum += current;
    current = (current * current) % M; // Calculate A_n+1
  }

  cout << sum << endl;
  return 0;
}