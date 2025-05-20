#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

vector<vector<int>> par;
vector<vector<int>> g;
vector<int> depth;

void dfs(int u, int p) {
    par[u][0] = p;
    for (int i = 1; i < 20; i++) {
        if (par[u][i-1] != -1)
            par[u][i] = par[par[u][i-1]][i-1];
        else
            par[u][i] = -1;
    }
    for (auto v : g[u]) {
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }
}

int get_lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != -1 && depth[par[u][i]] >= depth[v]) {
            u = par[u][i];
        }
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

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        g.assign(n+1, vector<int>());
        par.assign(n+1, vector<int>(20, -1));
        depth.assign(n+1, 0);

        for (int i = 0; i < n-1; i++) {
            int u, v; cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1, -1);

        int q; cin >> q;
        while (q--) {
            int x, y, z; cin >> x >> y >> z;
            int l1 = get_lca(x, y);
            int l2 = get_lca(x, z);
            int l3 = get_lca(y, z);
            int ans = l1;
            if (depth[l2] > depth[ans]) ans = l2;
            if (depth[l3] > depth[ans]) ans = l3;

            cout << ans << endl;
        }
    }

    return 0;
}
