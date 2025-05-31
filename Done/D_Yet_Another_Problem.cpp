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
    vi a(n+1, 0), pref(n+1, 0), non_zero(n+1, 0);
    map<int, set<int>> mpp[2];
    for(int i = 1; i<=n; i++){
        cin>>a[i];
        pref[i] = a[i]^pref[i-1];
        non_zero[i]= non_zero[i-1] + (a[i]!=0);
        mpp[i&1][pref[i]].insert(i);
    }int ans = 2;
    while(q--){
        int l, r; cin>>l>>r;
        if((pref[r]^pref[l-1])!=0) ans = -1;
        else if(non_zero[r]==non_zero[l-1]) ans = 0;
        else if((r-l+1)%2==1) ans = 1;
        else if(a[l]==0 || a[r]==0) ans = 1;
        else if(mpp[l&1][pref[l-1]].lower_bound(l)!=mpp[l&1][pref[l-1]].end() && *mpp[l&1][pref[l-1]].lower_bound(l)<=r) ans= 2;
        else ans= -1;
        cout<<ans<<endl;
    }
}

int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}