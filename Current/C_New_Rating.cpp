#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int calc(int idx, int type){
    if(idx == 0){
        if(type!=1)
            return 1;
        else 
            return 0;
    }
    if(dp[idx][type]!=-1) return dp[idx][type];
    if(ans>=a[idx]) 
    int ans = calc(idx-1, type);
    if(type==0){
        if(ans<a[idx]){
            ans = max(ans, calc(idx -1, 1));
            ans = max(ans, calc(idx-1, 0) - 1);
        }
        
    }else if(type==1){
        ans = max(ans, calc(idx - 1, 2));
    }

}
void Solve() {

}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}