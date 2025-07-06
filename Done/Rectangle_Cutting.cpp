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
    int l, r; cin>>l>>r;
    vvi dp(l+1, vi(r+1, 1e18));

    for(int i = 1; i<=l; i++){
        for(int j = 1; j<=r; j++){
            if(i==j) dp[i][j] = 0;
            else{
            for(int mid = 1; mid<i; mid++) dp[i][j] = min(dp[i][j], 1 + dp[mid][j] + dp[i-mid][j]);
            for(int mid = 1; mid<j; mid++) dp[i][j] = min(dp[i][j], 1 + dp[i][mid] + dp[i][j-mid]);
            }
        }
    }
    cout<<dp[l][r]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}