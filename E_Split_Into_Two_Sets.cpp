#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void dfs(){
    
}
void Solve() {
    int n; cin>>n;
    vvi g(n+1);
    for(int i = 0; i<n; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
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