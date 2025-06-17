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
    string s; cin>>s;
    map<int,int>mpp;
    for(int i = 0; i<n; i++){
        mpp[s[i]]++;
    } bool ok = false;
    for(int i = 1; i<n-1; i++){
        if(mpp[s[i]]!=1) ok = true;
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}