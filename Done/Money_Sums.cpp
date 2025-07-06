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
    int n;
    cin>>n;
    vi x(n);
    for(auto &X: x) cin>>X;

    int sum = accumulate(x.begin(), x.end(), 0);
    vector<vector<bool>> dp(n+1, vector<bool>(sum + 1, false));
    dp[0][0] = true;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=sum; j++){
            dp[i][j] = dp[i-1][j];

            if(j>=x[i-1] && dp[i-1][j-x[i-1]]) dp[i][j] = true;
        }
    }
    vi ans;
    for(int i = 1; i<=sum; i++){
        if(dp[n][i]) ans.push_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto &X: ans) cout<<X<<" ";
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}