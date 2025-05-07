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
    int n, x; cin>>n>>x;
    for(int i = 0; i<x; i++){
        cout<<i<<" ";
    }
    for(int i = x+1; i<n; i++){
        cout<<i<<" ";
    }if(x<n)cout<<x;
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