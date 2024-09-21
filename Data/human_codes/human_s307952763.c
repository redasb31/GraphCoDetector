#include <iostream>
#include <cstdint>
#include <valarray>

using namespace std;

int main(void) {
    int N;
    int64_t K;
    
    cin >> N >> K;

    valarray<int> s(0, 100000);
    for (int n = 0; n < N; n++) {
        int a, b;
        cin >> a >> b;
        s[a - 1] += b;
    }

    for (int n = 0; n < 100000; n++) {
        K -= s[n];
        if (K <= 0) {
            printf("%d\n", n + 1);
            return 0;
        }
    }
}
