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
    vi a(n,0);
    for(auto &x: a) cin>>x;
    sort(a.begin(), a.end());
    if(a[n-1]-a[0]-1>k){
        cout<<"Jerry"<<endl; return;
    }
    if(a[n-2]-a[0]>k){
        cout<<"Jerry"<<endl; return;
    }
    int S = 0;
    for(auto it: a) S+= it;
    if(S%2==1){
        cout<<"Tom"<<endl; return;
    }else{
        cout<<"Jerry"<<endl; return;
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}