#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> p, sz;
    DSU(int n): p(n,-1), sz(n,1) {
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int a,int b,ll &pairs, ll curr_d){
        a = find(a); b = find(b);
        if(a==b) return false;
        // when we join two components of sizes sz[a], sz[b],
        // we create sz[a]*sz[b] new unordered pairs whose
        // path-minimum is exactly curr_d
        pairs += (ll)sz[a]*sz[b]*curr_d;
        // union by size
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
        return true;
    }
};

void Solve() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    for(int i=0,u,v;i<N-1;i++){
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 1) Compute d[x] = distance from x to nearest leaf
    vector<int> d(N, INT_MAX);
    queue<int> q;
    for(int i=0;i<N;i++){
        if(adj[i].size()==1) {
            d[i]=0;
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(int v: adj[u]){
            if(d[v] > d[u]+1){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }

    // 2) Sort vertices by descending d[x]
    vector<int> order(N);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [&](int a,int b){ return d[a]>d[b]; });

    // 3) DSU activation
    vector<bool> active(N,false);
    DSU dsu(N);
    ll answer = 0;
    // First add the diagonal terms: each (x,x) contributes d[x]
    // (in the original sum i<=j; if you omit diagonals you must
    //  add +1 for the node with label=0, but here we trust the
    //  “min-distance’’ interpretation and include diagonals directly)
    for(int i=0;i<N;i++){
        answer += d[i];
    }
    // Now process in descending d: whenever we activate a node u
    // we union it with all active neighbors at weight = d[u]
    for(int u: order){
        active[u] = true;
        for(int v: adj[u]){
            if(active[v]){
                dsu.unite(u, v, answer, d[u]);
            }
        }
    }

    cout << answer << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        Solve();
    }
    return 0;
}
