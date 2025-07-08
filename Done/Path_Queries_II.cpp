#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> g;
vector<int> nums, parent, depth, heavy, head, pos, SegTree;
int cur_pos = 1, n;

int dfs(int v, int p) {
    int size = 1, max_subtree = 0;
    parent[v] = p;
    depth[v] = (p == -1 ? 0 : depth[p] + 1);
    for (int u : g[v]) {
        if (u == p) continue;
        int subtree = dfs(u, v);
        if (subtree > max_subtree) {
            heavy[v] = u;
            max_subtree = subtree;
        }
        size += subtree;
    }
    return size;
}

void decompose(int v, int h) {
    head[v] = h;
    pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h);
    for (int u : g[v]) {
        if (u != parent[v] && u != heavy[v])
            decompose(u, u);
    }
}

void build(int idx, int l, int r, const vector<int>& arr) {
    if (l == r) {
        SegTree[idx] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2*idx, l, mid, arr);
    build(2*idx+1, mid+1, r, arr);
    SegTree[idx] = max(SegTree[2*idx], SegTree[2*idx+1]);
}

void update(int idx, int l, int r, int pos, int val) {
    if (l > pos || r < pos) return;
    if (l == r && l == pos) {
        SegTree[idx] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2*idx, l, mid, pos, val);
    update(2*idx+1, mid+1, r, pos, val);
    SegTree[idx] = max(SegTree[2*idx], SegTree[2*idx+1]);
}

int query(int idx, int l, int r, int lq, int rq) {
    if (l > rq || r < lq) return -1e18;
    if (l >= lq && r <= rq) return SegTree[idx];
    int mid = (l + r) / 2;
    return max(query(2*idx, l, mid, lq, rq), query(2*idx+1, mid+1, r, lq, rq));
}

int path_query(int a, int b, int n) {
    int res = -1e18;
    while (head[a] != head[b]) {
        if (depth[head[a]] < depth[head[b]]) swap(a, b);
        res = max(res, query(1, 1, n, pos[head[a]], pos[a]));
        a = parent[head[a]];
    }
    if (depth[a] > depth[b]) swap(a, b);
    res = max(res, query(1, 1, n, pos[a], pos[b]));
    return res;
}

void Solve() {
    int q;
    cin >> n >> q;
    nums.assign(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> nums[i];
    g.assign(n+1, {});
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }
    parent.assign(n+1, -1);
    depth.assign(n+1, 0);
    heavy.assign(n+1, -1);
    head.assign(n+1, 0);
    pos.assign(n+1, 0);
    cur_pos = 1;
    dfs(1, -1);
    decompose(1, 1);

    vector<int> arr(n+1, 0);
    for (int i = 1; i <= n; i++) arr[pos[i]] = nums[i];
    SegTree.assign(4*(n+1), 0);
    build(1, 1, n, arr);

    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            int s, x; cin >> s >> x;
            update(1, 1, n, pos[s], x);
        } else {
            int a, b; cin >> a >> b;
            cout << path_query(a, b, n) << " "; 
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solve();
    return 0;
}
