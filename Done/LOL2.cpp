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
    vector<int> a(n,0);
    for(int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    int ans = 1;
    for(int i = 0; i<n; i++){
        if(!i) ans*= (a[i]-0+1);
        else ans*=(a[i] - a[i-1] + 1);
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