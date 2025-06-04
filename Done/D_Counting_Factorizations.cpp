#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int ncr(int n, int r){
    int num = 1, den = 1;
    for(int i = 0; i<n; i++){
        num*= (num-i);
        den*= (i+1);
    }
    return (num/den)%mod;
}
void Solve() {
    int n; cin>>n;
    set<int> st;
    for(int i = 0; i<n; i++){
        
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