#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi Rank, par;
vector<pair<int,int>> edges;

int find(int x){
    return par[x] == x ? x : par[x] = find(par[x]);
}

bool merge(int x, int y){
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (Rank[x] < Rank[y]) swap(x, y);
    par[y] = x;
    Rank[x] += Rank[y];
    return true;
}

void Solve() {
    int n, m, q;
    cin >> n >> m >> q;
    Rank.assign(n+1, 1);
    par.assign(n+1, 0);
    for(int i = 1; i <= n; i++) par[i] = i;
    edges.resize(m);
    for(int i = 0; i < m; i++){
        cin >> edges[i].first >> edges[i].second;
    }
    vector<pair<int,int>> queries(q);
    for(int i = 0; i < q; i++){
        int a, b = 0;
        cin >> a;
        if (a == 1) cin >> b;
        queries[i] = {a, b};
    }
    vector<bool> willDelete(m, false);
    for(auto &pr : queries){
        if (pr.first == 1) willDelete[pr.second - 1] = true;
    }
    int compCount = n;
    for(int i = 0; i < m; i++){
        if (!willDelete[i] && merge(edges[i].first, edges[i].second))
            compCount--;
    }
    vector<int> ans;
    for(int i = q - 1; i >= 0; i--){
        int a = queries[i].first;
        int b = queries[i].second;
        if (a == 1){
            if (merge(edges[b-1].first, edges[b-1].second))
                compCount--;
        } else {
            ans.push_back(compCount);
        }
    }
    for(int i = (int)ans.size() - 1; i >= 0; i--){
        cout << ans[i] << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
