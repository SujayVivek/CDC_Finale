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
    for(auto &x: a) cin>>x; int S = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i<n; i++){
        S+= a[i];
    }
    if(S-a[n-1]<a[n-1] || S%2==1){
        cout<<"NO"<<endl; return;
    }else{
        cout<<"YES"<<endl; return;
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}