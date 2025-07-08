#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n; 
vi indp, outdp;
vvi g;
vi sz, ans;
void dfs(int node, int prev){
    sz[node] = 1;
    for(auto nn: g[node]){
        if(nn==prev) continue;
        dfs(nn, node);
        sz[node]+= sz[nn];
        indp[node]+= indp[nn] + sz[nn];
    }
}
void dfs2(int node, int prev){
    if(prev!=-1)outdp[node] = (n-sz[node]) + outdp[prev] + indp[prev] - (indp[node] + sz[node]);
    for(auto nn: g[node]){
        if(nn==prev) continue;
        dfs2(nn, node);
    }
    ans[node] = indp[node] + outdp[node];
}
void Solve() {
    cin>>n;
    g.assign(n+1, {});
    for(int i = 0; i<n-1; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b), g[b].push_back(a);
    }
    indp.assign(n+1, 0);
    outdp.assign(n+1, 0);
    sz.assign(n+1, 0);
    ans.assign(n+1, 0);
    dfs(1, -1);
    dfs2(1, -1);
    for(int i = 1; i<=n; i++) cout<<ans[i]<<" ";
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