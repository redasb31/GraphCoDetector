#include <bits/stdc++.h>

using namespace std;

int ai, ao, at, al, aj, as, az, k;

int main() {
    cin >> ai >> ao >> at >> al >> aj >> as >> az;

    k += ao;

    k += ai - ai % 2;
    ai = ai % 2;

    k += min(min(al, aj), ai) * 3;

    int minn = min(min(al, aj), ai);
    al -= minn;
    aj -= minn;
    ai -= minn;

    k += aj / 2 * 2;

    k += al / 2 * 2;

    cout << k;
    return 0;
}
