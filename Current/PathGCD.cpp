#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
vi nums;
vvi g;
vvi dp, par;
vi depth;
void dfs(int node, int prev){
    par[node][0] = prev;
    dp[node][0] = nums[node];
    for(int i = 1; i<20; i++){
        if( par[node][i-1]!=-1 && par[par[node][i-1]][i-1]!=-1){
            par[node][i] = par[par[node][i-1]][i-1];
            dp[node][i] = __gcd(dp[node][i-1], dp[par[node][i-1]][i-1]);
        }
    }
    for(auto nn: g[node]){
        if(nn!=prev){depth[nn] = 1 + depth[node];dfs(nn, node);}
    }
}

int getlca_withgcd_onpath(int u, int v){
    int res = 0;
    if(depth[u]<depth[v]) swap(u, v);
    for(int i = 19; i>=0; i--){
        if(par[u][i]!=-1 && (depth[u]-depth[v])&(1<<i)) {res = __gcd(res, dp[u][i]);u = par[u][i];}
    }
    if(u==v) return __gcd(res, nums[u]);
    for(int i = 19; i>=0; i--){
        if(par[u][i] != -1 && par[u][i]!=par[v][i]){
            res = __gcd(res, dp[u][i]);
            res = __gcd(res, dp[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    res = __gcd(res, dp[u][0]);
    res = __gcd(res, dp[v][0]);
    res = __gcd(res, nums[par[u][0]]);
    return res;
}
void Solve() {
    // int t; cin>>t;
    int n; cin>>n;
    nums.assign(n+1, 0);
    g.assign(n+1, {});
    dp.assign(n+1, vi(20, -1));
    par.assign(n+1, vi(20, -1));
    depth.assign(n+1, 0); 
    for(int i = 1; i<=n; i++) cin>>nums[i];
    for(int i = 0; i<n-1; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b), g[b].push_back(a);
    }
    dfs(1, -1);
    int q; cin>>q;
    while(q--){
        int u , v; cin>>u>>v;
        cout<<getlca_withgcd_onpath(u, v)<<endl;
    }
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