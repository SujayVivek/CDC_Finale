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
    string A, B; cin>>A>>B;
    vvi dp(n+1, vi(m+1, 0)); int ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(A[i-1]==B[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 2);
            else dp[i][j] = max(dp[i][j], max(dp[i-1][j]-1, dp[i][j-1] -1));
            ans = max(dp[i][j], ans);
        }
    }cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}