#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, m;
vi b;
vector<vector<pair<int, int>>> g;

void Solve() {
    cin >> n >> m;
    b.assign(n + 1, 0);
    g.clear();
    g.resize(n + 1);

    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<int> maxBatteries(n + 1, 1e18);  // use 1e18 instead of 1e9 for safety with long long
    maxBatteries[1] = 0;

    // Min-heap: (distance traveled so far, current node, max edge weight used)
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [dist, node, mx] = pq.top();
        pq.pop();

        for (auto [nn, w] : g[node]) {
            int newDist = dist + b[node];
            if (newDist > w && max(mx, w) < maxBatteries[nn]) {
                int newMx = max(mx, w);
                maxBatteries[nn] = newMx;
                pq.push({newDist, nn, newMx});
            }
        }
    }

    if (maxBatteries[n] == 1e18) {
        cout << -1 << endl;
    } else {
        cout << maxBatteries[n] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
