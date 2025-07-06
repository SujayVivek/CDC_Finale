#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
vi x;
vvi dp;
int calc(int l, int r){
    
    if(l==r) return x[l];
    else if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    return dp[l][r] = max(x[l] - calc(l+1, r), x[r] - calc(l, r-1));
}
void Solve() {
    int n; cin>>n;
    x.assign(n,0); for(auto &X: x) cin>>X;
    int sum = accumulate(x.begin(), x.end(), 0);
    dp.assign(n, vi(n, -1));
    cout<< (sum + calc(0, n-1))/2<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}