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
        dfs(nn, node);
    }
}

int query(int node, int k){
    for(int i = 19; i>=0; i--){
        if(k&(1<<i)) node = par[node][i];
        if(node==-1) break;
    }
    return node;
}

void Solve() {
    int n, q; cin>>n>>q;
    g.assign(n+1, {});
    for(int i = 2; i<=n; i++){
        int x; cin>>x;
        g[i].push_back(x), g[x].push_back(i);
    }
    par.assign(n+1, vi(20, 0));
    dfs(1, -1);
    while(q--){
        int x, k; cin>>x>>k;
        cout<<query(x,k)<<endl;
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}