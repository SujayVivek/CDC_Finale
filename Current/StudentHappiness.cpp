#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vvi happy;
int n, m;
vvi dp;
int calc(int idx, int mask){
    if(idx>=m || mask>=1023 ) return 0;
    if(dp[idx][mask]!=-1) return dp[idx][mask];
    int ans = 0;
    ans = max(ans, calc(idx + 1, mask));
    for(int i = 0; i<n; i++){
        if((mask&(1<<i))==0){
            ans= max(ans, calc(idx + 1, mask|(1<<i)) + happy[idx][i]);
        }
    }
    return dp[idx][mask] = ans;
}
void Solve() {
    cin>>n>>m;
    happy.assign(m, vi(n, 0));
    dp.assign(m+1, vi(1030, -1));
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cin>>happy[i][j];
        }
    }
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