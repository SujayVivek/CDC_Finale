#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> Rank, par, f;

int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(Rank[x] < Rank[y]) swap(x, y);
    Rank[x] += Rank[y];
    par[y] = x;
}

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for(int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    sort(edges.begin(), edges.end());

    par.resize(n+1);
    Rank.assign(n+1, 1);
    f.assign(n+1, 1e18);

    for(int i = 1; i <= n; i++) {
        par[i] = i;
    }

    int ans = 1e18;

    for(auto e : edges) {
        int u = e[0], v= e[1], w = e[2];
        int ru = find(u);
        int rv = find(v);
        int min_w = min({f[ru], f[rv], w});
        merge(ru, rv);
        int root = find(ru);
        f[root] = min_w;
        if(find(1) == find(n)) {
            ans = min(ans, w + f[root]);
        }
    }

    cout<<ans<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        Solve();
    }
    return 0;
}
