#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi fen;
int n;
void update(int idx, int val){
    while(idx<=n){
        fen[idx]= (fen[idx] + val)%mod;
        idx+= idx&-idx;
    }
}
int query(int idx){
    int res = 0;
    while(idx>=1){
        res+= fen[idx];
        idx-= idx&-idx;
    }
    return res;
}
void Solve() {
    cin>>n;
    vi a(n,0);

    vi comp;
    for(auto &x: a){
        cin>>x;
        comp.push_back(x);
    }

    sort(comp.begin(), comp.end());

    //coordinate compression
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for(auto &x: a){
        x = lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
    }

    fen.assign(2*n + 1, 0);

    int ans = 0;
    for(int i = 0; i<n; i++){
        int cnt = query(a[i]-1);
        int dpSum = (cnt +1)%mod;
        update(a[i], dpSum);
        ans = (ans + dpSum)%mod;
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}