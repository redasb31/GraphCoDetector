#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
  
using namespace std;
  

#ifdef __GNUC__
template <class T> int popcount(T n);
template <> int popcount(unsigned int n) { return __builtin_popcount(n); }
template <> int popcount(int n) { return __builtin_popcount(n); }
template <> int popcount(unsigned long long n) { return __builtin_popcountll(n); }
template <> int popcount(long long n) { return __builtin_popcountll(n); }
#else
#define __typeof__ decltype
template <class T> int popcount(T n) { return n ? 1 + popcount(n & (n - 1)) : 0; }
#endif

#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define rforeach(it, c) for (__typeof__((c).rbegin()) it=(c).rbegin(); it != (c).rend(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CL(arr, val) memset(arr, val, sizeof(arr))
#define COPY(dest, src) memcpy(dest, src, sizeof(dest))
  
template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

template <class T> void sort(vector<T>& c) { sort(c.begin(), c.end()); }
template <class T> void unique(vector<T>& c) { c.erase(unique(c.begin(), c.end()), c.end()); }
template <class T> void sort_unique(vector<T>& c) { sort(c); unique(c); }

typedef long long ll;
typedef pair<int, int> pint;
  
template <class T, class U> ostream& operator<<(ostream& os, pair<T, U>& p) { os << "( " << p.first << ", " << p.second << " )"; return os;  }
 
template <class T> string to_s(const T& a) { ostringstream os; os << a; return os.str(); }
template <class T> T to_T(const string& s) { istringstream is(s); T res; is >> res; return res; }
 
bool valid_pos(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }
  
template <class T> void print(T a, int n, const string& deli = " ", int br = 1) { for (int i = 0; i < n; ++i) { cout << a[i]; if (i + 1 != n) cout << deli; } while (br--) cout << endl; }
template <class T> void print(const T& c, const string& deli = " ", int br = 1) { foreach (it, c) { cout << *it; if (++it != c.end()) cout << deli;--it; } while (br--) cout << endl; }
template <class T> void print2d(T a, int w, int h, int width = -1, int br = 1) { for (int i = 0; i < h; ++i) { for (int j = 0; j < w; ++j) {    if (width != -1) cout.width(width); cout << a[i][j] << ' '; } cout << endl; } while (br--) cout << endl; }
  
template <class T> void input(T& a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }
template <class T, class U> void input(T& a, U& b, int n) { for (int i = 0; i < n; ++i) cin >> a[i] >> b[i]; }
 
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
 
const double PI = acos(-1.0);
const int mod = 1000000007;



const int M = 210 * 5;
ll fact[210];
ll combi[210][210];
ll ten_pow[M];
vector<vector<ll> > digits_dp(const vector<int>& digits)
{
    int n = digits.size();

    static ll dp[210][M + 30];
    CL(dp, 0);
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = i; j >= 0; --j)
            for (int k = M - 1; k >= 0; --k)
                (dp[j + 1][k + digits[i]] += dp[j][k]) %= mod;

    vector<vector<ll> > res(n + 1, vector<ll>(M));
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < M; ++j)
            res[i][j] = dp[i][j];
    return res;
}
ll gao(const vector<int>& a, const vector<int>& digits)
{
    int n = a.size();

    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        vector<int> d;
        for (int j = 0; j < n; ++j)
            if (i != j)
                d.push_back(digits[j]);
        vector<vector<ll> > d_pat = digits_dp(d);

        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                ll pat = 0;
                for (int u = 0; u <= (n - 1) - j; ++u)
                    (pat += (combi[(n - 1) - j][u] * fact[u] % mod) * fact[j]) %= mod;
                (pat *= d_pat[j][k]) %= mod;

                (res += ((a[i] * ten_pow[k]) % mod) * pat) %= mod;
            }
        }
    }

    return res;
}
int main()
{
    fact[0] = 1;
    for (int i = 1; i < 210; ++i)
        fact[i] = (fact[i - 1] * i) % mod;

    for (int i = 0; i < 210; ++i)
    {
        combi[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            combi[i][j] = (combi[i - 1][j] + combi[i - 1][j - 1]) % mod;
    }

    ten_pow[0] = 1;
    for (int i = 1; i < M; ++i)
        ten_pow[i] = (ten_pow[i - 1] * 10) % mod;


    int n;
    vector<int> a, d;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        d.push_back(s.size());
        a.push_back(to_T<int>(s));
    }

    ll res = gao(a, d);
    if (find(all(a), 0) != a.end())
    {
        vector<int> _a, _d;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] != 0)
            {
                _a.push_back(a[i]);
                _d.push_back(d[i]);
            }
        }

        ll sub = gao(_a, _d);
        res = (res - sub + mod) % mod;
    }

    cout << res << endl;
}