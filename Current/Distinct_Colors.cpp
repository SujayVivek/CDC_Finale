#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<set<int>> vs;      
vector<vector<int>> g;  
vector<int> ans;          

void dfs(int node, int prev){
    for(auto nn: g[node]){
        if(nn == prev) continue;
        dfs(nn, node);

        if(vs[nn].size() > vs[node].size()){
            swap(vs[nn], vs[node]);
        }
        for(int color : vs[nn]) vs[node].insert(color);
    }
    ans[node] = vs[node].size();
}

void Solve() {
    int n; cin >> n;
    vs.assign(n+1, set<int>());
    g.assign(n+1, {});
    ans.assign(n+1, 0);

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        vs[i].insert(x);
    }

    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, 0); 

    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
