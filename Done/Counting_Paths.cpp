#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vvi g;
vvi par;
vi depth;

void dfs(int node, int prev){
    par[node][0] = prev;
    for(int i = 1; i<20; i++){
        if(par[node][i-1]!=-1){
            par[node][i] = par[par[node][i-1]][i-1];
        }else{
            par[node][i] = -1;
        }
    }
    for(auto nn: g[node]){
        if(nn==prev) continue;
        depth[nn] = 1 + depth[node];
        dfs(nn, node);
    }
}

int get_lca(int u, int v){
    if(depth[u]<depth[v]) swap(u, v);

    for(int i = 19; i>=0; i--){
        if(par[u][i]!=-1 && ((depth[u]-depth[v])&(1<<i))){
            u = par[u][i];
        }
    }
    if(u==v) return u;
    for(int i = 19; i>=0; i--){
        if(par[u][i]!=par[v][i] && u!=-1 && v!=-1){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
void aggregate(vi &agg, int node, int prev){
    for(auto nn: g[node]){
        if(nn!=prev) {
            aggregate(agg, nn, node);
            agg[node]+= agg[nn];
        }
    }
}
void Solve() {
    int n, q;
    cin>>n>>q;
    g.assign(n+1, {});
    par.assign(n+1, vi(20, -1));
    depth.assign(n+1, 0);
    for(int i = 0; i<n-1; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b), g[b].push_back(a);
    }
    depth[1] = 0;
    dfs(1, -1);
    vi agg(n+1, 0);
    while(q--){
        int a, b; cin>>a>>b;
        int lca = get_lca(a, b);
        agg[a]++, agg[b]++;
        agg[lca]--;
        if(par[lca][0]!=-1) agg[par[lca][0]]--;
    }
    // for(int i = 1; i<=n; i++) cout<<agg[i]<<" ";
    // cout<<endl;
    aggregate(agg, 1, -1);
    for(int i = 1; i<=n; i++) cout<<agg[i]<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}