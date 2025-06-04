#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
int n, k; 
int dp[5005][5005];
int hot[5005], cold[5005];
int a[5005];

// int calc(int idx, int other){
//     if(idx>n) return 0;
//     if(dp[idx][other]!=-1) return dp[idx][other];
//     int last_cur = a[idx-1];
//     int cost_cur = ((a[idx]==last_cur)?hot[a[idx]]: cold[a[idx]]);
//     int cost_other = ((a[idx]==other)?hot[a[idx]]:cold[a[idx]]);
//     int ans_cur = cost_cur + calc(idx + 1, other);
//     int ans_other = cost_other + calc(idx + 1, last_cur);
//     return dp[idx][other] = min(ans_cur, ans_other);
// }
void Solve() {
    cin>>n>>k;
    a[0] = 0;
    for(int i = 1; i<=n; i++){
        cin>>a[i];
    }
    for(int i = 1; i<=k; i++){
        cin>>cold[i];
    }
    for(int i = 1; i<=k; i++){
        cin>>hot[i];
    }
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=k; j++) dp[i][j] = 1e18;
    }
    dp[0][0] = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=k; j++){
            int temp = dp[i-1][j];
            if(a[i]==a[i-1] || j==a[i]){
                temp+= hot[a[i]];
            }else{
                temp+= cold[a[i]];
            }
            dp[i][j] = min(dp[i][j], temp);
            dp[i][a[i-1]] = min(dp[i][a[i-1]], temp);
        }
    }int ans = 1e18;
    for(int i = 0; i<=k; i++){
        ans = min(ans, dp[n][i]);
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}