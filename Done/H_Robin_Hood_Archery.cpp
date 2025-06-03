#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
vi val;
void Solve() {
    int n, q; cin>>n>>q;
    vi a(n,0), pref(n+1, 0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        pref[i+1] = pref[i]^val[a[i]];
    }
    while(q--){
        int l, r; cin>>l>>r;
        l--;
        if(pref[l]==pref[r]){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    val.assign(1e6+10, 0);
    for(int i = 0; i<=1e6 + 5; i++) val[i] = rng();
    while (tt_--) {
        Solve();
    }
    return 0;
}