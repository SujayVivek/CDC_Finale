#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vvi dp;
vi a;
int n;
int Happy(int i, int j, int K){
    return __gcd(a[i], a[j])*(K+1)*(abs(a[i]-a[j]));
}
int calc(int idx, int mask){
    if(idx >= n) return 0;
    if(dp[idx][mask]!=-1 ) return dp[idx][mask];
    int ans = 0;
    for(int i = 0; i<2*n-1; i++){
        for(int j = i+1; j<2*n; j++){
            if((mask&(1<<i)) || (mask&(1<<j))) continue;
                ans = max(ans, Happy(i, j, idx) + calc(idx + 1, mask|(1<<i)|(1<<j)));
        }
    }
    return dp[idx][mask] = ans;
}
void Solve() {
    cin>>n;
    a.assign(2*n, 0);
    dp.assign(2*n+1, vi(1<<2*n, -1));
    for(int i = 0; i<2*n; i++) cin>>a[i];
    cout<<calc(0, 0)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}