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
    int n, c; cin>>n>>c;
    vector<int> a(n,0);
    for(auto &x: a) cin>>x;

    sort(a.begin(), a.end(), greater<int>());
    int coins = 0;
    int mul = 0;
    for(int i = 0; i<n; i++){
        if(a[i]*(1<<mul)>c) continue;
        else{
            mul++;
            coins++;
        }
    }
    cout<<n-mul<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}