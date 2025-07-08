#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi indp;
vvi g;
vi centroid;
int n;
void dfs(int node, int prev){
    indp[node] = 1;
    bool ok = true;
    for(auto nn: g[node]){
        if(nn == prev) continue;
        dfs(nn, node);
        indp[node]+= indp[nn];
        if(indp[nn]> (n/2)) ok = false;
    }
    if(n-indp[node]> (n/2)) ok = false;
    if(ok) centroid.push_back(node);
}
void Solve() {
    cin>>n;
    g.assign(n+1, {});
    indp.assign(n+1, 0);
    centroid.clear();
    for(int i = 0; i<n-1; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b), g[b].push_back(a);
    }

    dfs(1, -1);
    if(centroid.size()==0) cout<<-1<<endl;
    else cout<<centroid[0]<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}