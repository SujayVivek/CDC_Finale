#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<int> nums, in, out, fen;
int cnt = 1;

void update(int n, int idx, int val) {
    while (idx < n) {
        fen[idx] ^= val;
        idx += (idx & -idx);
    }
}

int query(int idx) {
    int res = 0;
    while (idx > 0) {
        res ^= fen[idx];
        idx -= (idx & -idx);
    }
    return res;
}

int range_query(int l, int r) {
    return query(r) ^ query(l - 1);
}

void dfs(int node, int parent) {
    in[node] = cnt++;
    for (int child : g[node]) {
        if (child != parent) dfs(child, node);
    }
    out[node] = cnt;
}

void Solve() {
    int n; cin >> n;
    g.assign(n + 1, {});
    nums.assign(n + 1, 0);
    in.assign(n + 1, 0);
    out.assign(n + 1, 0);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    string S; cin >> S;
    for (int i = 1; i <= n; i++)
        nums[i] = (1 << (S[i - 1] - 'a'));
    
    //building the euler vector
    dfs(1, 0);
    
    //building the fenwick tree with euler vector
    int size = 2 * n + 5;
    fen.assign(size, 0);
    for (int i = 1; i <= n; i++)
        update(size, in[i], nums[i]);
    
        //query
    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 0) {
            int node; char c; cin >> node >> c;
            int new_val = (1 << (c - 'a'));
            int delta = nums[node] ^ new_val;
            nums[node] = new_val;
            update(size, in[node], delta);
        } else {
            int node; cin >> node;
            int val = range_query(in[node], out[node] - 1);
            if (__builtin_popcount(val) <= 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
