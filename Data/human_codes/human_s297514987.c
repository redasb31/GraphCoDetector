#include <bits/stdc++.h>

using namespace std;

long long ans,p,cur,t,cnt[200010];
string s;

int main()
{
    cin >> s;
    p = 2019;
    cnt[0] = 1,t = 1;
    for(int i = s.size() - 1;i >= 0;i--)
    {
        cur = (cur + t*(s[i] - '0')%p) % p;
        t = t*10 % p;
        ans += cnt[cur]++;
    }
    
    cout << ans << endl;
    return 0;
}