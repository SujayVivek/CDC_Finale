#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
static const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // dist_t[u] = min time to reach u
        // dist_w[u] = among min-time ways, min waits
        vector<int> dist_t(n+1, INF), dist_w(n+1, INF);

        // Min-heap over (time, waits, node), lex order
        using State = tuple<int,int,int>;
        priority_queue<State, vector<State>, greater<State>> pq;

        dist_t[1] = 0;
        dist_w[1] = 0;
        pq.emplace(0, 0, 1);

        while (!pq.empty()) {
            auto it = pq.top();
            int ct = get<0>(it), cw = get<1>(it), u = get<2>(it);
            // auto [ct, cw, u] = pq.top();
            pq.pop();
            // stale?
            if (ct > dist_t[u] || (ct == dist_t[u] && cw > dist_w[u])) 
                continue;
            // first time we pop n, it's optimal
            if (u == n) break;

            int d = (int)adj[u].size();
            for (int j = 0; j < d; j++) {
                int v = adj[u][j];
                // need wait seconds so that (ct + wait) % d == j
                int wait = (j - (ct % d) + d) % d;
                int nt = ct + wait + 1;
                int nw = cw + wait;
                if (nt < dist_t[v] || (nt == dist_t[v] && nw < dist_w[v])) {
                    dist_t[v] = nt;
                    dist_w[v] = nw;
                    pq.emplace(nt, nw, v);
                }
            }
        }

        // answer for this test
        cout << dist_t[n] << " " << dist_w[n] << "\n";
    }
    return 0;
}