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

    vi ans;
    for(int i = 0; i<a.size(); i++){
        if(ans.size()==0 || a[i]>ans.back()) ans.push_back(a[i]);
        else{
            auto it = lower_bound(ans.begin(), ans.end(), a[i]);
            *it = a[i];
        }
    }
    cout<<ans.size()<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}