#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vvi g;
vi a;
vi outdp;

void dfs(int node, int prev, int prevprev){
    outdp[node] = a[node];
    if(prev!=-1)outdp[node] = max(outdp[node], a[node]-a[prev]);
    if(prevprev!=-1) outdp[node] = max(outdp[node], a[node]-a[prev]+outdp[prevprev]);
    for(auto nn: g[node]){
        if(nn!=prev){
            dfs(nn, node, prev);
        }
    }
}
void Solve() {
    int n; cin>>n;
    a.assign(n+1, 0);
    for(int i = 1; i<=n; i++) cin>>a[i];
    g.assign(n+1,{});
    for(int i = 0; i<n-1; i++){
        int A, b; cin>>A>>b;
        g[A].push_back(b), g[b].push_back(A);
    }
    outdp.assign(n+1, -1);
    outdp[1] = a[1];
    dfs(1, -1, -1);
    for(int i = 1; i<=n; i++)cout<<outdp[i]<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}