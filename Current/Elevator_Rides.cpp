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
    int n, W; cin>>n>>W;
    vi a(n,0); for(int i = 0; i<n; i++) cin>>a[i];

    vector<pair<int, int>> dp(1 << n, {n + 1, 0}); //min rides, cur_weight

    dp[0] = {1, 0};

    for(int mask = 1; mask<(1<<n); mask ++){
        for(int i = 0; i<n; i++){
            if(mask&(1<<i)){
                auto prev = dp[mask^(1<<i)];
                if(prev.second + a[i]<=W){
                    prev.second += a[i];
                }else{
                    prev.first++;
                    prev.second = a[i];
                }
                dp[mask] = min(dp[mask], prev);
            }
        }
    }
    cout<<dp[(1<<n)-1].first<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}