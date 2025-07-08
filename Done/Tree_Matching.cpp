#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<int> dp0, dp1; //dp0 means it is not, and dp1 means it is matched

void dfs(int u, int p) {
    dp0[u] = 0;
    dp1[u] = 0;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp0[u] += max(dp0[v], dp1[v]); //here we don't care, but we aren't yet matching v to u, since we want to know out of all u to v, which one will be the best
    }
    for (auto v : g[u]) {
        if (v == p) continue;
        int temp = dp0[u] - max(dp0[v], dp1[v]) + dp0[v] + 1;
        dp1[u] = max(dp1[u], temp);
    }
}

void Solve() {
    int n; cin >> n;
    g.assign(n + 1, {});
    dp0.assign(n + 1, 0);
    dp1.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    dfs(1, -1);
    cout << max(dp0[1], dp1[1]) << endl;
}

int32_t main() {
    int tt_ = 1;
    while (tt_--) {
        Solve();
    }
    return 0;
}
