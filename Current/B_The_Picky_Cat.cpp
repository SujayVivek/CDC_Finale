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
    int n; cin>>n; vi a(n,0);
    for(auto &x: a) cin>>x;
    int p = (n+1)/2;
    // cout<<"Needed = "<<p<<endl;
    int q = 0;
    for(int i = 1; i<n; i++){
        if(abs(a[0])<abs(a[i]))q++;
    }
    int r = n-q;

    if(r<=p || n-r+1==p)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}