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
    vector<int> b(n,0);
    for(int i = 0; i<n; i++) cin>>b[i];

    int mn = b[0];
    for(int i = 1; i<n; i++){
        if(mn + (mn - 1)<b[i]) {cout<<"NO"<<endl; return;}
        mn = min(mn, b[i]);
    }
    cout<<"YES"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}