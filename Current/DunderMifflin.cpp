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
    vector<int> dp(2, vector<int>(3, 0)), dpn(2, vector<int>(3, 0));
    dp[0][0] = 1;
    for(int i = 0; i<n; i++){
        memset(dp, 0, sizeof(ndp));
        for(int a = 0; a<2; a++){
            for(int l = 0; l<3; l++){
                int v = dp[a][l];
                if(!v){
                    if(a==0)dpn[1][l] = (dpn[1][l] + v)%mod;
                    if(l<2){
                        dpn[a][l+1] = (dpn[a][l+1] + v)%mod;
                    }
                }
                
            }
        }
        memcpy(dp, dpn, sizeof(dp));
    }
    int ans = 0;
    for(int a = 0; a < 2; a++) for(int l = 0; l < 3; l++)
        ans = (ans + dp[a][l]) % mod;
    cout << ans;
    return;

}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}