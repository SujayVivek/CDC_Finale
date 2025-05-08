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
    int n; cin>>n;
    vi a(n,0);
    for(auto &x: a) cin>>x;
    int mx = -LLONG_MAX; int ans = 0;
    for(int i = 0; i<n; i++){
        if(a[i]>=mx){mx = a[i]; continue;}
        int bits = 64-__builtin_clzll(mx-a[i]);
        ans = max(ans, bits);
        // mx = max(mx, a[i] + (1<<bits)-1);
        // cout<<ans<<" "<<bits<<" "<<mx<<endl;
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