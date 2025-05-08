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
    vvi grid(n, vi(n,0));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>grid[i][j];
        }
    }
    vi company_A(n, 0) , company_b(n,0);
    for(auto &x: company_A) cin>>x;
    for(auto &x: company_B) cin>>x;
    
    
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}