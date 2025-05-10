#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi fact(505, 0);
void Solve() {
    int n; cin>>n; int S = n*(n+1)/2; int ans = 0;
    for(int i = 1; i<=n; i++){
        ans+= abs(i*n-S);
    }
    cout<<fact[n-1]*ans-1<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    fact[0] = 1;
    for(int i = 1; i<=501; i++){
        fact[i] = fact[i-1]*i;
    }
    while (tt_--) {
        Solve();
    }
    return 0;
}