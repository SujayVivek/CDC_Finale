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
    vvi grid(n+1, vi(m+1, 0));
    int mx = 0;
    for(int i = 1; i<=n; i++) for(int j = 1; j<=m; j++){
        cin>>grid[i][j];
        mx = max(mx, grid[i][j]);
    }
    int ans = 0, cnt = 0, res = 1e18;
    for(int i = 1; i<=n; i++) for(int j = 1; j<=m; j++) if(grid[i][j] < mx) ans = max(ans, grid[i][j]);
    vi row(n+1, 0), col(m+1, 0), rowP(n+1, 0), colP(m+1, 0);
    for(int i =1; i<=n; i++) for(int j = 1; j<=m; j++) {
            if(grid[i][j] == mx) {
                cnt++, rowP[i]++, colP[j]++;
            }
            row[i] = max(row[i], grid[i][j]), col[j] = max(col[j], grid[i][j]);
    }
    for(int i = 1; i<=n; i++) for(int j = 1; j<=m; j++) {
            int val = ((rowP[i] +colP[j] -(grid[i][j] == mx))== cnt)?ans : mx;
            res = min(res, max(val, max(row[i], col[j]) - 1));
    }
    cout <<res<< endl;
}


int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}