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
    int n, k; cin >> n >> k;
    vi v(n, 0), cost;
    for(auto &x: v) cin>>x; int tot = 0;
    for(int i = 0; i < n; i++) {
        tot += __builtin_popcountll(v[i]);
        for(int j = 0; j < 60; j++) {
            int val = (1LL<<j)-1;
            if(k<val+1) break;
            if(!(v[i] & val+1)) {
                cost.push_back(val+1);
            }
        }
    }
    sort(cost.begin(), cost.end()); int bud = 0, cnt = 0;
    for(int c : cost) {
        if(c <= k-bud) {
            bud += c, cnt++;
        } else break;
    }
    tot+= cnt;
    cout<<tot<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}