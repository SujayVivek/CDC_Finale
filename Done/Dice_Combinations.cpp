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
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i = 0; i<=n; i++){
        for(int dice = 1; dice<=6 && i + dice<=n; dice++){
            if(i + dice <= n) dp[i + dice] = (dp[i+dice] + dp[i])%mod;
        }
    }
    cout<<dp[n]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}