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
    int n, x; cin>>n>>x;
    vi c(n,0);
    for(auto &X: c) cin>>X;
    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    for(int i = 0; i<=x; i++){
        for(int j = 0; j<(int)c.size(); j++){
            if(i + c[j]<=x) dp[i + c[j]] = (dp[i + c[j]] + dp[i])%mod;
        }
    }
    cout<<dp[x]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}