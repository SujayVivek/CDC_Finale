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
    int x, a, b, c; cin>>x>>a>>b>>c;
    deque<int> dq;
    int sum = 0;
    vi ans;
    dq.push_back(x); sum = x;
    while((int)dq.size()<k){
        int X = dq.back();
        int nx = (X*a + b)%c;
        sum+= nx;
        dq.push_back(nx);
    }
    ans.push_back(sum);
    for(int i = k+1; i<=n; i++){
        int X = dq.back();
        int O = dq.front();
        dq.pop_front();
        int nx = (X*a + b)%c;
        sum = sum + nx - O;
        dq.push_back(nx);
        ans.push_back(sum);
    }
    int xoR = 0;
    for(int i = 0; i<ans.size(); i++) xoR^=ans[i];
    
    cout<< xoR <<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}