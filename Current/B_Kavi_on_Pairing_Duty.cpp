#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n; cin>>n;
    vi dp(n+1, 0), divSum(n+1, 0);
    for(int i = 1; i<=n; i++){
        for(int j = i+i; j<=n; j+=i)
            divSum[j]++;
    } dp[0] = 1; int sum = 1;
    for(int i = 1; i<=n; i++){
        dp[i] = (sum + divSum[i])%mod;
        sum = (sum + dp[i])%mod;
    }cout<<dp[n]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}