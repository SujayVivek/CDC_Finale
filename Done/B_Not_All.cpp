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
    int n, m; cin>>n>>m;
    vi a(n,0); map<int,int>mpp;
    for(int i = 0; i<n; i++) {
        cin>>a[i];
        mpp[a[i]]++;
    }
    int cnt = 0;
    for(int i = 1; i<=m; i++){
        if(!mpp[i]){
            cout<<0<<endl; return;
        }
    }
    for(int i = n-1; i>=0; i--){
        mpp[a[i]]--; cnt++;
        if(mpp[a[i]]==0 && a[i]<=m) break;
        
    }
    cout<<cnt<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}