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
    int n; cin >> n;
    vi a;
    a.push_back(-1e18);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (a.back() == x);
        else a.push_back(x);
    }
    a.push_back(-1e9);
    int ans = 0;
    for (int i = 1; i < a.size() - 1; i++) 
        if (a[i - 1] < a[i] && a[i] > a[i + 1]) ans++;
 
    cout << ans << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}