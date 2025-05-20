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
    vi a(n,0);
    int one = 0, zer = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]==0) zer++;
        else one++;
    }
    if(one==0 || zer==0){
        cout<<"YES"<<endl; return;
    }
    for(int i = 1; i<n; i++){
        if(a[i]==0 && a[i-1]==0){
            cout<<"YES"<<endl; return;
        }
    }
    cout<<"NO"<<endl; return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}