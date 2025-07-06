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
void Solve() {
    int n; cin>>n;
    cout<< (dp[n-1][0] + dp[n-1][1])%mod<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    int N = 1e6+1;
    dp.assign(N+1, vi(2, 0));
    dp[0][1] = dp[0][0] = 1;

    for(int i = 1; i<N; i++){
        int op1 = (dp[i-1][0] + dp[i-1][1])%mod; // don't extend both
        int op2 = (dp[i-1][0])%mod; //extend when not linked
        int op3 = (2*dp[i-1][0])%mod; //extend any 1
        int op4 = (dp[i-1][1])%mod; //extend when linked

        dp[i][0] = (op1 + op2 + op3)%mod;
        dp[i][1] = (op1 + op4)%mod;
    }

    while (tt_--) {
        Solve();
    }
    return 0;
}