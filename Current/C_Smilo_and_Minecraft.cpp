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
    int n, m, k; cin>>n>>m>>k;
    vector<string> vs(n);
    for(int i = 0; i<n; i++) cin>>vs[i];
    vector<vector<int>>pref(n+1, vector<int>(m+1, 0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            pref[i+1][j+1] = pref[i][j+1] + pref[i+1][j] - pref[i][j] + (vs[i][j]=='g');
        }
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(vs[i][j]=='.'){
                int x1 = min(i+k-1, n-1); int y1 = min(j+k-1, m-1);
                int x2 = max(i-k+1, 0LL); int y2 = max(j-k+1, 0LL);
                int g = pref[x1+1][y1+1] - pref[x1+1][y2] - pref[x2][y1+1] + pref[x2][y2];
                ans = max(ans, pref[n][m] - g);
            }
        }
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