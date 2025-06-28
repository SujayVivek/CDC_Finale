#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void Solve() {
    int X, Y, Z, C;
    cin >> X >> Y >> Z >> C;
    if (X == Y) {
        cout << 0 << endl;
        return;
    }
    int64_t ans = 2 * C;
    int64_t best = LLONG_MAX;
    if (X % Y == 0) {
        int64_t n = X;
        for (int64_t i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (i % Y == 0) best = min(best, abs(Z - i) + C);
                int64_t j = n / i;
                if (j % Y == 0) best = min(best, abs(Z - j) + C);
            }
        }
    }
    if (Y % X == 0) {
        int64_t n = Y;
        for (int64_t i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (i % X == 0) best = min(best, abs(Z - i) + C);
                int64_t j = n / i;
                if (j % X == 0) best = min(best, abs(Z - j) + C);
            }
        }
    }
    if (best < LLONG_MAX) ans = min(ans, best);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt_ = 1;
    cin >> tt_;
    while (tt_--) Solve();
    return 0;
}
