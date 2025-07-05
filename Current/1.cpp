#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    vector<vector<array<int,3>>> adj(N+1);
    for(int i = 0; i < M; i++){
        int u, v, d, t;
        cin >> u >> v >> d >> t;
        adj[u].push_back({v,d,t});
        adj[v].push_back({u,d,t});
    }

    const ll INF = LLONG_MAX/4;
    vector<vector<ll>> dist(2, vector<ll>(N+1, INF));
    dist[0][A] = 0;
    using State = pair<ll, pair<int,int>>; 
    priority_queue<State, vector<State>, greater<>> pq;
    pq.push({0,{A,0}});

    while(!pq.empty()){
        auto [cd, info] = pq.top(); pq.pop();
        auto [u, used] = info;
        if(cd > dist[used][u]) continue;
        for(auto &e : adj[u]){
            int v = e[0], d = e[1], t = e[2];
            ll w1 = cd + d + t;
            if(w1 < dist[used][v]){
                dist[used][v] = w1;
                pq.push({w1,{v,used}});
            }
            if(used==0){
                ll w2 = cd + d;
                if(w2 < dist[1][v]){
                    dist[1][v] = w2;
                    pq.push({w2,{v,1}});
                }
            }
        }
    }

    cout << min(dist[0][B], dist[1][B]) << "\n";
    return 0;
}
