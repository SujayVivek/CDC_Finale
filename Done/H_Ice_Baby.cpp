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
    multiset<int> mst;
    for(int i = 0; i<n; i++){
        int l, r; cin>>l>>r;
        auto it = mst.upper_bound(r);
        if(it!=mst.end()){
            mst.erase(it);
        }
        mst.insert(l);
        cout<<mst.size()<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}