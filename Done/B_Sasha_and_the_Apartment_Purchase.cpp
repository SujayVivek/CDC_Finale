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
    int n, k; cin>>n>>k;
    vi v(n,0);
    for(int i = 0; i<n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    int L = -1, R = -1;
    for(int i = 0; i<n; i++){
        int a = i, b = n-i-1;
        if(abs(b-a)-k<=1){
            if(L==-1) L = v[i];
            R = v[i];
        }
    }
    cout<<R-L+1<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}