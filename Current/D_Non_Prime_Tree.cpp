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
vi depth;
vi par;
vi ans;
int l, k;
int n;
void dfs(int node, int prev){
    par[node] = prev;
    for(auto nn: g[node]){
        if(nn!=prev){
            depth[nn] = 1 + depth[node];
            dfs(nn, node);
        }
    }
}
void dfs2(int node, int prev){
    if(depth[node]%2==0) {ans[node] = l; l+=2;}
    else {ans[node] = 2*n - k; k+=2;}
    for(auto nn: g[node]){
        if(nn!=prev) dfs2(nn, node);
    }
}
void Solve() {
    cin >>n;
    g.assign(n+1, {}), depth.assign(n+1, 0);
    par.assign(n+1, 0);
    depth[1] = 1;
    for(int i = 0; i<n-1 ;i++){
        int u, v; cin>>u>>v;
        g[u].push_back(v), g[v].push_back(u);
    }
    l = 2;
    k = 0;
    dfs(1, -1);
    ans.assign(n+1, 0);
    dfs2(1, -1);
    for(int i = 1; i<=n; i++){
        if(g[i].size()==1 && par[i]!=-1 && abs(ans[par[i]] - ans[i]) == 2) ans[i] = ans[par[i]]-1>0?ans[par[i]]-1: ans[par[i]]+ 1;
    }
    for(int i = 1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
    return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}