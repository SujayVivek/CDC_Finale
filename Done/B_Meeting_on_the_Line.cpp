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
    vi x(n,0), t(n,0);
    for(int i = 0; i<n; i++) cin>>x[i];
    for(int j = 0; j<n; j++) cin>>t[j];
    vi ans; 
    for(int i = 0; i<n; i++) {ans.push_back(x[i]-t[i]), ans.push_back(x[i] + t[i]);}
    int mx = 0, mn = 1e18;
    for(auto a: ans){
        mx = max(mx, a), mn = min(mn, a);
    }
    cout<<(mn + mx)/2;
    if((mx + mn)%2) cout<<".5";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}