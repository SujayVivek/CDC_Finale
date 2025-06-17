#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, m; 
vvi g;
vi vis;
vi tin;
vi low;
vi mark;
int timer;
void dfs(int node, int prev){
    vis[node] = 1;
    tin[node] = low[node] = timer; timer++;
    int child = 0; // this is just for the root node, with prev = -1;
    for(auto nn: g[node]){
        if(nn==prev) continue;
        if(!vis[nn]){
            dfs(nn, node);
            low[node] = min(low[node], low[nn]);
            if(low[nn]<=tin[node] && prev!=-1) mark[node]++;
            child++;
        }else{
            low[node] = min(low[node], tin[nn]);
        }
    }
    if(child>1 && prev==-1) mark[node]++;
}
void Solve() {
    cin>>n>>m;
    vis.assign(n+1, 0);
    g.assign(n+1, {});
    low.assign(n+1, 1e18);
    tin.assign(n+1, 1e18);
    mark.assign(n+1, 0);
    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b), g[b].push_back(a);
    }
    timer = 0;
    set<int> st;
    for(int i = 1; i<=n; i++){
        if(!vis[i]) dfs(i, -1);
    }
    for(int i = 1; i<=n; i++){
        if(mark[i]==2) st.insert(i);
    }
    //all these nodes are the articulation points with two edges, that totally give the number of components to be equal to 3 when removed
    //now i just need to find which one among these contain a simple graph!
    
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}