#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
#define int long long
#define endl "\n"

struct pair_hash {
    size_t operator()(const pair<int,int> &p) const {
        return std::hash<long long>()((p.first << 32) ^ p.second);
    }
};

vector<vector<pair<int,int>>> g;
vector<int> b;

void Solve() {
    int n, m;
    cin >> n >> m;
    b.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    g.assign(n+1, {});
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});
    unordered_set<pair<int,int>, pair_hash> vis;
    vis.reserve(m * 2);
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int X = cur.ff, u = cur.ss;
        if (u == n) {
            cout << X << "\n";
            return;
        }
        auto key = make_pair(u, X);
        if (vis.find(key) != vis.end()) continue;
        vis.insert(key);
        for (auto &e : g[u]) {
            int v = e.ff, w = e.ss;
            if (X + b[u-1] < w) continue;
            int X2 = max(X, (int)w);
            auto key2 = make_pair(v, X2);
            if (vis.find(key2) == vis.end()) {
                pq.push({X2, v});
            }
        }
    }
    cout << -1 << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
