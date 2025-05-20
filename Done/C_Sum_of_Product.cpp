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
    for(auto &x : a) cin>>x;
    vi suff(n,0); suff[n-1] = a[n-1];
    for(int i = n-2; i>=0; i--){
        suff[i] = suff[i+1] + a[i];
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans += a[i]*(suff[i]-a[i]);
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}