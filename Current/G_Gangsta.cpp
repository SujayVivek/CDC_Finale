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
    int n; string s; cin>>n>>s;
    vi a(n+1, 0);
    for(int i = 1; i<=n; i++) a[i] = a[i-1] + ((s[i-1] == '1')?1:-1);
    sort(a.begin(), a.end()); int ans = 0, res = 0;
    for(int i = 0; i<=n; i++) ans = ans - res, res = res + a[i], ans = ans + i*a[i];
    // cout<<ans<<" HI"<<endl;
    cout<<(ans + (n*(n+1)*(n+2))/6)/2<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}