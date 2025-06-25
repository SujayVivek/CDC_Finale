#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void Solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int center = -1;
    for (int i = 1; i <= n; i++) {
        if ((int)adj[i].size() == 2) {
            center = i;
            break;
        }
    }
    if (center == -1) {
        cout << "NO" << endl;
        return;
    }
    int u = adj[center][0];
    int w = adj[center][1];

    vector<pair<int,int>> ans;
    ans.emplace_back(w, center);
    ans.emplace_back(center, u);
    function<void(int,int,int)> dfs = [&](int v, int p, int depth) {
        for (int to : adj[v]) {
            if (to == p) continue;
            if (depth % 2 == 0) {
                ans.emplace_back(to, v);
            } else {
                ans.emplace_back(v, to);
            }
            dfs(to, v, depth + 1);
        }
    };
    dfs(u, center, 0); 
    dfs(w, center, 1); 
    cout << "YES" << endl;
    for (auto &e : ans) {
        cout << e.first << " " << e.second << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) Solve();

    return 0;
}
