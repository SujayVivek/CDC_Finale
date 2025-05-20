#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<vector<int>> par;
vector<int> depth;
vector<int> partial;

void dfs(int u, int p) {
    par[u][0] = p;
    for (int i = 1; i < 20; ++i) {
        par[u][i] = par[par[u][i-1]][i-1];
    }
    for (int v : g[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = 19; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = par[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; --i) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void dfs_propagate(int u, int p) {
    for (int v : g[u]) {
        if (v != p) {
            dfs_propagate(v, u);
            partial[u] += partial[v];
        }
    }
}

void Solve() {
    int n;
    cin >> n;
    g.assign(n + 1, {});
    par.assign(n + 1, vector<int>(20));
    depth.assign(n + 1, 0);
    partial.assign(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0);

    int q;
    cin >> q;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        int anc = lca(x, y);
        partial[x] += z;
        partial[y] += z;
        partial[anc] -= z;
        if (par[anc][0] != -1)
            partial[par[anc][0]] -= z;
    }

    dfs_propagate(1, -1);

    for (int i = 1; i <= n; ++i) {
        cout << partial[i] << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
