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
    for(auto &a: c) cin>>a;
    sort(c.begin(), c.end());
    vvi dp(x+1, vi(n, 0));
    // int latest = 0;
    dp[0][0] = 1;
    for(int i = 0; i<=x; i++){
        for(int latest = 0; latest<n; latest++){
            for(int j = latest; j<n; j++){
                if(i + c[j]<=x) dp[i + c[j]][j] = (dp[i][latest])
            }
        }
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}