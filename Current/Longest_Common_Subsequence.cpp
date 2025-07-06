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
    int n, m; cin>>n>>m;

    vi a(n), b(m);
    for(int i = 0; i<n; i++) cin>>a[i];
    for(int i = 0; i<m; i++) cin>>b[i];

    vvi dp(n+1, vi(m+1, 0));
    vi ans;

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i-1]==b[j-1]){
                if(dp[i][j]<1 + dp[i-1][j-1]) ans.push_back(a[i-1]);
                dp[i][j] = 1 + dp[i-1][j-1];
                
            }else{
                dp[i][j] = max({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
        }
    }

    //recover the lcs array
    vi lcs;
    int i = n, j = m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            lcs.push_back(a[i-1]);
            i--, j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    cout<<lcs.size()<<endl;
    for(auto &x: lcs) cout<<x<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}