#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<tuple<int,int,int>> edges(M);
        for (int i = 0; i < M; ++i) {
            int u,v,w;
            cin >> u >> v >> w;
            --u; --v;
            edges[i] = {u,v,w};
        }
        vector<vector<int>> g0(N);
        vector<pair<int,int>> E0;   
        for (auto &e : edges){
            int u,v,w;
            tie(u,v,w) = e;
            if (w == 0) {
                g0[u].push_back(v);
                g0[v].push_back(u);
                E0.emplace_back(u,v);
            }
        }
        if (N == 2) {
            cout << 0 << "\n";
            continue;
        }
        vector<char> vis(N,0);
        queue<int> q;
        vis[0] = 1; 
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g0[u]) if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
        bool connected = true;
        for (int i = 0; i < N; ++i) {
            if (!vis[i]) { connected = false; break; }
        }
        if (!connected) {
            cout << 0 << "\n";
            continue;
        }
        int full = (1<<N) - 1;
        int best = M+1;
        for (int mask = 1; mask < full; ++mask) {
            if (!(mask & 1)) continue;     
            if (mask == full)   continue;  
 
            int cut_sz = 0;
            for (auto &e : E0) {
                int u = e.first, v = e.second;
                bool inS_u = (mask >> u) & 1;
                bool inS_v = (mask >> v) & 1;
                if (inS_u ^ inS_v) ++cut_sz;
            }
            best = min(best, cut_sz);
        }
        cout << best << "\n";
    }

    return 0;
}
