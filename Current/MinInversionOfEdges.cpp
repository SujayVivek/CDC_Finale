#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

vector<vector<pair<int, int>>> g;
vector<int> dp;
int n;

void dfs1(int node, int parent) {
    for (size_t i = 0; i < g[node].size(); ++i) {
        int child = g[node][i].first;
        int weight = g[node][i].second; 
        if (child == parent) continue;
        dfs1(child, node);
        dp[node] += dp[child] + weight;
    }
}

void dfs2(int node, int parent) {
    for (size_t i = 0; i < g[node].size(); ++i) {
        int child = g[node][i].first;
        int weight = g[node][i].second;
        if (child == parent) continue;
        dp[child] = dp[node] + (weight == 0 ? 1 : -1);
        dfs2(child, node);
    }
}
void Solve() {
    cin >> n;
    g.assign(n + 1, vector<pair<int, int>>());
    dp.assign(n + 1, 0);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(make_pair(v, 0)); 
        g[v].push_back(make_pair(u, 1)); 
    }

    dfs1(1, 0);    
    dfs2(1, 0);     

    int min_inv = *min_element(dp.begin() + 1, dp.end());
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] == min_inv) ans.push_back(i);
    }

    cout << min_inv << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}
