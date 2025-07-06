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
    int n, m; cin>>n>>m;
    vi x(n);
    for(int i = 0; i<n; i++) cin>>x[i];

    vvi dp(n+1, vi(m+2, 0));
    if(x[0] == 0){
        for(int i = 1; i<=m; i++){
            dp[0][i] = 1;
        }
    }
    else dp[0][x[0]] = 1;
    
    for(int i = 1; i<n; i++){
        for(int j = 1; j<=m; j++){
            if(x[i]==0 || x[i]==j){
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1])%mod;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i<=m; i++) ans= (ans + dp[n-1][i])%mod;
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}