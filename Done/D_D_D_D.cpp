#include <bits/stdc++.h>
using namespace std;
#define int long long
const int64_t INF64 = (int64_t)4e18;

void Solve(){
    int n, m, l;
    cin >> n >> m >> l;

    vector<int> A(l);
    int64_t S_tot = 0;
    int64_t minOdd = INF64;
    for(int i = 0; i < l; i++){
        cin >> A[i];
        S_tot += A[i];
        if (A[i] & 1) minOdd = min(minOdd, (int64_t)A[i]);
    }

    vector<vector<int>> g(n+1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // BFS from 1 to compute dist[] and 2-color to check bipartiteness
    vector<int64_t> dist(n+1, INF64);
    vector<int> color(n+1, -1);
    queue<int> q;

    dist[1] = 0;
    color[1] = 0;
    q.push(1);

    bool isBip = true;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v: g[u]){
            // distance update
            if(dist[v] > dist[u] + 1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            // 2-coloring
            if(color[v] == -1){
                color[v] = color[u] ^ 1;
            } else if(color[v] == color[u]){
                isBip = false;
            }
        }
    }

    // Build and print answer
    // For each vertex i: let d = dist[i].
    // If d > S_tot → impossible.
    // Else if non-bipartite → OK.
    // Else (bipartite):
    //   if (S_tot % 2 == d % 2) → OK
    //   else if (minOdd < INF && S_tot - minOdd >= d) → OK
    //   else → NO
    string ans;
    ans.reserve(n);
    for(int i = 1; i <= n; i++){
        int64_t d = dist[i];
        bool ok = false;
        if(d <= S_tot){
            if(!isBip){
                ok = true;
            } else {
                if((S_tot % 2) == (d % 2)){
                    ok = true;
                } else if(minOdd < INF64 && S_tot - minOdd >= d){
                    ok = true;
                }
            }
        }
        ans.push_back(ok ? '1' : '0');
    }

    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
    return 0;
}
