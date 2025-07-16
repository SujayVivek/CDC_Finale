#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)4e18;

int main(){

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int,ll>>> adj(N);
    for(int i = 0; i < M; i++){
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    int src, dest, k;
    cin >> src >> dest >> k;
    int maxEdges = k + 1;  

    vector<vector<ll>> best(maxEdges+1, vector<ll>(N, INF));
    best[0][src] = 0;

    typedef pair<ll, pair<int,int>> State;
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push(make_pair(0LL, make_pair(src, 0)));

    while(!pq.empty()){
        ll cost = pq.top().first;
        int u   = pq.top().second.first;
        int e   = pq.top().second.second;
        pq.pop();

        if(cost != best[e][u]) 
            continue;

        if(u == dest){
            cout << cost << "\n";
            return 0;
        }

        if(e == maxEdges) 
            continue;

        for(auto &ed : adj[u]){
            int v = ed.first;
            ll  w = ed.second;
            ll nc = cost + w;
            if(nc < best[e+1][v]){
                best[e+1][v] = nc;
                pq.push(make_pair(nc, make_pair(v, e+1)));
            }
        }
    }

    cout << "No route available\n";
    return 0;
}
