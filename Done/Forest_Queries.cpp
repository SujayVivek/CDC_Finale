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
    int n, q; cin>>n>>q;
    vector<string> g(n);
    for(auto &x: g) cin>>x;
    vector<vector<int>> pref(n+1, vector<int>(n+1 , 0));
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            pref[i][j] = (g[i-1][j-1]=='*');
            pref[i][j]+= pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];
        }
    }
    while(q--){
        int x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
        cout<< pref[x2][y2] - pref[x2][y1-1] - pref[x1-1][y2] + pref[x1-1][y1-1]<<endl;
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}