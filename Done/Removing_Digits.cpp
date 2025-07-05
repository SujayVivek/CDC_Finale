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
    int num; cin>>num;
    
    vector<int> dp(num + 1, 1e18);
    dp[num] = 0;

    for(int i = num; i>=0; i--){
        vi dig;
        if(dp[i]==1e18) continue;

        int x = i;
        while(x){
            dig.push_back(x%10);
            x/=10;
        }
        
        for(int j = 0; j<dig.size(); j++){
            if(i - dig[j]>=0){
                dp[i-dig[j]] = min(dp[i-dig[j]], dp[i] + 1);
            }
        }
    }
    cout<<dp[0]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}