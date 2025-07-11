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
    vi a(n,0);
    for(auto &x: a) cin>>x;
    int s = accumulate(a.begin(), a.end(), 0LL);
    vvi dp(n, vi(n, 0));
    for(int l = n-1; l>=0; l--){
        for(int r = l; r<=n-1; r++){
            if(l==r){
                dp[l][r] = a[l];
            }else{
                dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
            }
        }
    }
    cout<< (s + dp[0][n-1])/2<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}