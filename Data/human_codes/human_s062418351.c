#include <bits/stdc++.h>

#define st              first
#define nd              second
#define pb              push_back
#define lwb             lower_bound
#define upb             upper_bound
#define all(a)          (a).begin(), (a).end()
#define Reset(s, n)     memset(s, n, sizeof(s))
#define Sz(a)           int((a).size())
#define Max(a, b, c)    max(max((ll)(a), (ll)(b)), (ll)(c))
#define Min(a, b, c)    min(min((ll)(a), (ll)(b)), (ll)(c))
#define Unique(a)       (a).resize(unique(all(a)) - (a).begin())
#define bit(n, i)       (((n) >> (i)) & 1)
#define cntbit(n)       __builtin_popcountll(n)

using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
const ll INF = 1e9;
const ld PI = acos((ld) -1);
const ld EPS = 1e-12;
inline bool isPrime (ll x){ if(x <= 1) return 0; if(x <= 3) return 1; if (!(x % 2) || !(x % 3)) return 0; ll s = sqrt(1.0 * x) + EPS; for(ll i = 5; i <= s; i += 6){if (!(x % i) || !(x % (i + 2))) return 0;}return 1;}
inline ll fpow(ll n, ll k, ll p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline int inv(int a, ll p = MOD) {return fpow(a, p - 2, p);}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline void onbit(ll &a, int i){a |= 1LL << i;}
inline void offbit(ll &a, int i){onbit(a, i), a -= (1LL << i);}

const int N = 3e3 + 5;

int n, m, k;
ll a[N], b[N];
ll f[N][N][3];

void solve(){
   cin >> n;
   std::vector<pair<int, int>> b(n + 1);
   for(int i = 1; i <= n; i++){
      cin >> a[i];
      b[i] = {a[i], i};
   }
   b[0] = {INF, INF};
   sort(all(b), greater<pair<int,int>>());
   ll res = 0;
   for(int k = 1; k <= n; k++){
      int x = b[k].st;
      int y = b[k].nd;
      int len = n - k + 1;
      for(int i = 1; i + len - 1 <= n; i++){
         f[i][len][0] = max(f[i - 1][len + 1][0] + b[k].st * abs(b[k].nd - i), 
                            f[i][len + 1][1] + b[k].st * abs(b[k].nd - i));
         f[i][len][1] = max(f[i - 1][len + 1][0] + b[k].st * abs(b[k].nd - (i + len - 1)), 
                            f[i][len + 1][1] + b[k].st * abs(b[k].nd - (i + len - 1)));
         res = Max(res, f[i][len][0], f[i][len][1]);
      }
   }
   cout << res << "\n";

  

}

int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cout << fixed << setprecision(10);
   //    freopen("input.txt", "r", stdin);
   //    freopen("output.txt", "w", stdout);
   int query = 1;
   // cin >> query;
   int start = 1000 * clock() / CLOCKS_PER_SEC;
   while(query--) solve();
   cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC  - start << "ms\n";
}
