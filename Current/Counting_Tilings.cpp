#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

int n, m;
int dp[1001][1<<11];

void generate_masks(int idx, int mask, vector<int> &msks, int new_mask){
    if(idx == n){
        msks.push_back(new_mask);
        return;
    }
    if(mask & (1<<idx)){
        generate_masks(idx+1, mask, msks, new_mask);
    } else {
        
        generate_masks(idx+1, mask, msks, new_mask | (1<<idx));

        if(idx+1 < n && !(mask & (1<<(idx+1))))
            generate_masks(idx+2, mask, msks, new_mask);
    }
}

int calc(int col, int mask){
    if(col == m){
        return mask == 0;
    }
    if(dp[col][mask] != -1) return dp[col][mask];
    vector<int> msks;
    generate_masks(0, mask, msks, 0);
    int ans = 0;
    for(auto v: msks){
        ans = (ans + calc(col + 1, v)) % mod;
    }
    return dp[col][mask] = ans;
}

void Solve() {
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << calc(0, 0) << endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
