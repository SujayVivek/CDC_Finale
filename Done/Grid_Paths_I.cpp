#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n; cin>>n;
    vector<string> grid(n);
    for(auto &s: grid) cin>>s;
    vvi dp(n, vi(n, 0));
    if(grid[n-1][n-1]!='*')dp[n-1][n-1] = 1;
    for(int i = n-1; i>=0; i--){
        for(int j = n-1; j>=0; j--){
            if(dp[i][j]==0) continue;
            if(i-1>=0 && grid[i-1][j]!='*') dp[i-1][j]  = (dp[i-1][j] + dp[i][j])%mod;
            if(j-1>=0 && grid[i][j-1]!='*') dp[i][j-1] = (dp[i][j-1] + dp[i][j])%mod;
        }
    }
    cout<<dp[0][0]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}