#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n, m;
vector<vector<bool>> g;
i64 ans = 0;
map<tuple<int, int, int>, i64> memo;

i64 dfs(int mask, int cur, int start, int size) {
    if (__builtin_popcount(mask) >= 3 && g[cur][start]) {
        // Complete cycle back to start node
        ans += 1;
    }

    if (memo.count({mask, cur, start})) return memo[{mask, cur, start}];

    i64 total = 0;
    for (int next = 0; next < size; ++next) {
        if (!(mask & (1 << next)) && g[cur][next]) {
            total += dfs(mask | (1 << next), next, start, size);
        }
    }

    return memo[{mask, cur, start}] = total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    g.assign(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x][y] = g[y][x] = true;
    }

    for (int size = 3; size <= n; size++) {
        // Fix the start node to be the last one in current subgraph
        int start = size - 1;
        memo.clear();
        dfs(1 << start, start, start, size);
    }

    ans /= 2; // Each cycle counted twice (both directions)
    cout << ans << '\n';

    return 0;
}
