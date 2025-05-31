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
int n;
vi dp;
void dfs(int node, int prev){
    dp[node] = 1;
    for(auto nn: g[node]){
        if(nn!=prev){
        dfs(nn, node);
            dp[node] = max(dp[node], dp[nn] + 1);
        }
    }
}
void Solve() {
    cin>>n;
    g.assign(n+1, {});
    dp.assign(n+1, 0);
    for(int i = 0; i<n-1; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1, -1);
    int ans = accumulate(dp.begin(), dp.end(), 0);
    int f = 1; 
    for(int i = 1; i<=n-1; i++){
        f = (f*2)%mod;
    } ans = (ans*f)%mod;
    cout<< ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}