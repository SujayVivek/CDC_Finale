#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g, par;
vector<int> depth;

void dfs(int node, int prev) {
    par[node][0] = prev;
    for (int i = 1; i < 20; i++) {
        if (par[node][i-1] != -1)
            par[node][i] = par[par[node][i-1]][i-1];
        else
            par[node][i] = -1;
    }
    for (auto nn : g[node]) {
        if (nn == prev) continue;
        depth[nn] = depth[node] + 1;
        dfs(nn, node);
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != -1 && ((depth[u] - depth[v]) & (1 << i)))
            u = par[u][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != -1 && par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void Solve() {
    int n, q;
    cin >> n >> q;
    g.assign(n + 1, {});
    par.assign(n + 1, vector<int>(20, -1));
    depth.assign(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }
    dfs(1, -1);
    while (q--) {
        int a, b; cin >> a >> b;
        int lca = get_lca(a, b);
        cout << depth[a] + depth[b] - 2 * depth[lca] << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
