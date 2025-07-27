#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vector<int> par;
vvi g;
vi vis;
int st, en;
bool dfs(int node, int p){
    vis[node] =1 ;
    par[node] = p;
    for(auto nn: g[node]){
        if(!vis[nn]){
            if(dfs(nn, node)) return true;
        }else{
            if(nn!=p){
                en = nn, st = node;
                return true;
            }
        }
    }
    return false;
}
void Solve() {
    int n, m; cin>>n>>m;
    g.assign(n+1, {});
    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b), g[b].push_back(a);
    }
    st = -1, en = -1;
    vis.assign(n+1, 0);
    par.assign(n+1, 0);
    for(int i = 1; i<=n; i++)
        if(!vis[i])
            if(dfs(i, -1)){
                vector<int> ans;
                ans.push_back(st);
                int cst = st;
                // cout<<en<<" "<<st<<endl;
                while(st!=en){
                    st = par[st];
                    ans.push_back(st);
                }
                // ans.push_back(en);
                ans.push_back(cst);
                cout<<ans.size()<<endl;
                for(auto x: ans) cout<<x<<" ";
                return;
            }
    cout<<"IMPOSSIBLE";
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}