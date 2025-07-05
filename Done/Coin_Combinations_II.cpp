#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (auto &i : v)
            cin >> i;
        vector<vector<int>> dp(n, vector<int>(x + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= x; j++)
            {
                if ((i == 0) && (j == 0))
                {
                    dp[i][j] = 1;
                }
                if (i > 0)
                {
                    dp[i][j] += dp[i - 1][j];
                    dp[i][j] %= ((int)(1e9 + 7));
                }
                if ((j - v[i]) >= 0)
                {
                    dp[i][j] += dp[i][j - v[i]];
                    dp[i][j] %= ((int)(1e9 + 7));
                }
            }
        }
        cout << dp[n - 1][x] << "\n";
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}