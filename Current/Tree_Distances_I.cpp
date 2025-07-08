#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;

vector<int> bfs(int start, int n) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

void Solve() {
    int n; cin >> n;
    g.assign(n + 1, {});
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> d1 = bfs(1, n);
    int A = max_element(d1.begin(), d1.end()) - d1.begin();

    vector<int> da = bfs(A, n);
    int B = max_element(da.begin(), da.end()) - da.begin();

    vector<int> db = bfs(B, n);

    for (int i = 1; i <= n; i++) {
        cout << max(da[i], db[i]) << " ";
    }
    cout << endl;
}

int32_t main() {
    int tt_ = 1;
    while (tt_--) {
        Solve();
    }
    return 0;
}
