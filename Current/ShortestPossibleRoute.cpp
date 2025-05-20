#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vvi dis;
int n; 
vvi dp;
int calc(int start, int curIdx, int mask){
    if(mask== ((1<<n))-1)return dis[curIdx][start];
    if(dp[curIdx][mask]!=-1) return dp[curIdx][mask];
    int ans = 1e18;
    for(int i = 0; i<n; i++){
        if(!(mask&(1<<i))) ans = min(ans, dis[curIdx][i] + calc(start, i, mask|(1<<i)));
    }
    return dp[curIdx][mask] = ans;
}
void Solve() {
    cin>>n;
    dis.assign(n+1, vi(n+1, 0));
    dp.assign(n+1, vi(1<<n+5, -1));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>dis[i][j];
        }
    }int mx = 1e18;
    for(int i = 0; i<n; i++){
        mx = min(mx, calc(i, 0, 0));
    }cout<<mx<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}