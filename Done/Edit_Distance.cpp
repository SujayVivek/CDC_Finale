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
    string s1, s2; cin>>s1>>s2;
    int n = s1.length(), m = s2.length();

    vvi dp(n+1, vi(m+1, 1e18));
    for(int i = 0; i<=n; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j<=m; j++){
        dp[0][j] = j;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
            dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
        }
    }
    cout<< dp[n][m]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}