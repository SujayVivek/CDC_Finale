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
    vi a(n,0);
    int first = -1, last = -1;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        if(a[i]==1 && first==-1){
            first= i;
        }
        if(a[i]==1) last = i;
    }
    if(first==-1 || last-first+1<=x){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
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