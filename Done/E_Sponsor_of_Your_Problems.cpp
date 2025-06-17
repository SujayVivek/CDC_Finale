#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int dp[11][2][2]; 
string L, R;
int dfs(int pos, bool tightL, bool tightR) {
    if (pos == L.size()) return 0;
    if (dp[pos][tightL][tightR]!= -1) return dp[pos][tightL][tightR];

    int lo = tightL?(L[pos]-'0'):0, hi = tightR?(R[pos]-'0'):9;
    int res = 1e18;
    for (int d = lo; d <= hi; ++d) {
        int cost = (d == (L[pos] - '0')) + (d == (R[pos] - '0'));
        res = min(res, cost + dfs(pos + 1, tightL && (d == lo), tightR && (d == hi)));
    }
    return dp[pos][tightL][tightR] = res;
}

void Solve() {
    string l, r; cin >> l >> r;
    while (l.size()< r.size()) l = '0' + l;
    L = l; R = r;
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, true, true) << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
