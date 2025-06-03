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
vi res;
int mx;
void calc(int idx, int ele, vi ans){
    if(idx >= n){
        if(ans.size()>=mx){res = ans;}
        return;
    }
    if(dp[])
}
void Solve() {
    int n; cin>>n;
    a.assign(n, 0);
    dp.assign(n+1, vi(n+1, -1));
    for(auto &x: a) cin>>x;
    mx = 0;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}