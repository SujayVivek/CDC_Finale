#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void Solve() {
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) cin >> price[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<int> dp(x+1, 0);
    int mx = 0;
    
    for(int i = 0; i<n; i++){
        for(int j  = x; j>0; j--){

            if(price[i]>j) continue;
            dp[j] = max(dp[j], pages[i] + dp[j-price[i]]);
        }
    }
    cout<<dp[x]<<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
