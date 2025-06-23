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
    vvi g(n+1, vi(n+1, 0));
    for(int i = 1; i<=n; i++) for(int j = 1; j<=n; j++) cin>>g[i][j];
    vi a(n+1, 0), b(n+1 ,0);
    for(int i = 1; i<=n; i++) cin>>a[i];
    for(int i = 1; i<=n; i++) cin>>b[i];
    vvi dp(n+1, vi(2, 1e18));
    dp[1][0] = 0;
    dp[1][1] = a[1];
    for(int i = 2; i<=n; i++){
        for(int x = 0; x<2; x++){
            for(int y = 0; y<2; y++){
                bool ok = true;
                for(int j = 1; j<=n; j++){
                    if(g[i][j] + x == g[i-1][j] + y) ok = false;
                }
                if(ok){
                    if(x==0)
                        dp[i][x] = min(dp[i][x], dp[i-1][y]);
                    else
                        dp[i][x] = min(dp[i][x], dp[i-1][y] + a[i]);
                    
            }
        }
    }
}
    int ans = min(dp[n][0], dp[n][1]);
    if(ans==1e18){cout<<-1<<endl; return;}
    dp.assign(n+1, vi(2, 1e18));
    dp[1][0] = 0;
    dp[1][1] = b[1];
    for(int j = 2; j<=n; j++){
        for(int x = 0; x<2; x++){
            for(int y= 0; y<2; y++){
                bool ok = true;
                for(int i = 1; i<=n; i++){
                    if(g[i][j] +x == g[i][j-1] + y) ok =false;
                }
                if(ok){
                if(x==0)
                    dp[j][x] = min(dp[j][x], dp[j-1][y]);
                else{
                    dp[j][x] = min(dp[j][x], dp[j-1][y] + b[j]);
                }
            }
        }
    }
}
    int p = min(dp[n][0], dp[n][1]);
    if(p==1e18){
        cout<<-1<<endl; return;
    }
    cout<<ans + p<<endl;
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