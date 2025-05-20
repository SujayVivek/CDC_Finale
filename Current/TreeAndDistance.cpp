#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<vector<int>> g;
vector<vector<int>> dp;
int ans = 0;
int k;

void dfs(int node, int prev) {
    dp[node][0] = 1;
    for (auto nn : g[node]) {
        if (nn == prev) continue;
        dfs(nn, node);

        for (int i = 0; i < k; i++) {
            ans += dp[node][i] * dp[nn][k - i - 1];
        }
        for (int i = 1; i <= k; i++) {
            dp[node][i] += dp[nn][i - 1];
        }
    }
}

void Solve() {
    int n;
    cin >> n >> k;
    g.assign(n + 1, {});
    dp.assign(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ans = 0;
    dfs(1, 0);
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
