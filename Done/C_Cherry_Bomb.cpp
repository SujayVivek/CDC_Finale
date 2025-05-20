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
    vi a(n,0), b(n,0);
    int mn = 1e18, mx = 0;
    for(int i = 0; i<n; i++) {
        cin>>a[i]; mn = min(a[i], mn), mx = max(a[i], mx);
    } int Sum = -1; set<int> st;
    for(int i = 0; i<n; i++){
        cin>>b[i]; if(b[i]!=-1){
            Sum = b[i] + a[i];
            st.insert(Sum);
        }
    }
    if(st.size()>1){
        cout<<0<<endl;return;
    }
    if(Sum==-1){
        cout<<mn+k-mx+1<<endl;
    }else{
        int ok = 1;
        for(int i = 0; i<n; i++){
            if(Sum-a[i]>k || Sum-a[i]<0) ok = 0;
        }
        cout<<ok<<endl;
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