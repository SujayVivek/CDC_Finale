#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi dp0, dp1;
int n,k;
vector<vector<pair<int,int>>>g;
// dfs(u, p):
// dp0[u] = maximum matching‐weight in subtree(u) if u is NOT matched to its parent
// dp1[u] = maximum matching‐weight in subtree(u) if u IS matched to its parent
void dfs(int node, int prev){
    dp0[node] = dp1[node] = 0;
    for(auto &e : g[node]){
        int nn = e.first; int w = e.second;
        if(nn==prev) continue;
        dfs(nn,node);
        // if u is not matched to parent, v may or may not match back to u:
        dp0[node] += max(dp0[nn], dp1[nn] + w);
        // if u IS matched to parent, u cannot match to any child:
        dp1[node] += dp0[nn];
    }
}
void Solve() {
    cin>>n>>k;
    dp0.assign(n+1, 0), dp1.assign(n+1, 0);
    g.assign(n+1,{});
    int S = 0;
    for(int i = 0; i<n-1; i++){
        int a, b, c; cin>>a>>b>>c;
        S+= c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    if(n==1) cout<<0<<endl;
    else if(k>=2) cout<<S<<endl;
    else{
        dfs(1, 0);
        cout<<dp0[1]<<endl;
    }
     // since root cannot be matched with parent
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