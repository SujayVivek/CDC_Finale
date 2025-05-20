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
    int r, x; cin>>r>>x;
    if(r>=1600 && r<=2999 && x==1){
        cout<<"Yes"<<endl; return;
    }else if(r>=1200 && r<=2399 && x==2){
        cout<<"Yes"<<endl; return;
    }
    cout<<"No"<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}