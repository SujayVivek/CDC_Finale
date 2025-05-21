#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int calc(int x) {
    if (x<=1) return 0;
    return 64- __builtin_clzll(x - 1);
}
void Solve() {
    int n, m, a, b; cin>>n>>m>>a>>b;
    int r = min(a, n - a + 1), c = min(b, m - b + 1);
    int ans1 = calc(m) + calc(r),  ans2 = calc(n) + calc(c);
    cout<<1+min(ans1, ans2) <<endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt_;
    cin >> tt_;
    while (tt_--) Solve();
    return 0;
}
