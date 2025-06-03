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
    int n, q; cin>>n>>q;
    vi B(n,0); for(auto &x: B) cin>>x;
    vvi Q; 
    int qq = q;
    while(qq--){
        int x, y, z; cin>>x>>y>>z; x--, y--, z--;
        Q.push_back({x, y, z});
    }
    vi ans = B;
    for(int i = q-1; i>=0; i--){
        int x = Q[i][0], y = Q[i][1], z = Q[i][2];
        ans[x] = max(ans[x], ans[z]), ans[y] = max(ans[y], ans[z]);
        ans[z] = -1;
    }
    for(int i = 0; i<n; i++){
        if(ans[i]==-1) ans[i] = B[i];
    }
    vi res = ans;
    for(int i = 0; i<q; i++){
        int x = Q[i][0], y = Q[i][1], z = Q[i][2];
        ans[z] = min(ans[x], ans[y]);
    }
    if(ans == B){
            for(auto x: res) cout<<x<<" ";
            cout<<endl;
    }else{
        cout<<-1<<endl;
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