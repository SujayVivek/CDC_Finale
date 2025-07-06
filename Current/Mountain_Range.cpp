#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegTree {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, 0);
    }

    void update(int pos, int val) {
        pos += size;
        tree[pos] = val;
        while (pos > 1) {
            pos >>= 1;
            tree[pos] = max(tree[2 * pos], tree[2 * pos + 1]);
        }
    }

    int query(int l, int r) {
        int res = 0;
        l += size;
        r += size;
        while (l <= r) {
            if (l % 2 == 1) res = max(res, tree[l++]);
            if (r % 2 == 0) res = max(res, tree[r--]);
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};

struct SparseTable {
    vector<vector<int> > st;
    vector<int> log;
    int n;

    void build(const vector<int> &a) {
        n = a.size();
        int K = 32 - __builtin_clz(n);
        log.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) log[i] = log[i/2] + 1;

        st.assign(n, vector<int>(K));
        for (int i = 0; i < n; i++) st[i][0] = a[i];
        for (int j = 1; j < K; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    int query(int l, int r) {
        if (l > r) return -1e9;
        int j = log[r - l + 1];
        return max(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    SparseTable st;
    st.build(h);

    SegTree seg;
    seg.init(n);

    vector<pair<int, int> > idx_h;
    for (int i = 0; i < n; i++) idx_h.push_back({h[i], i});
    sort(idx_h.begin(), idx_h.end());

    for (int z = 0; z < n; z++) {
        int i = idx_h[z].second;
        int best = 0;

        // glide right
        int lo = i + 1, hi = n - 1, rbest = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (st.query(i + 1, mid) < h[i]) {
                rbest = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (rbest != -1) best = max(best, seg.query(i + 1, rbest));

        // glide left
        lo = 0, hi = i - 1;
        int lbest = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (st.query(mid, i - 1) < h[i]) {
                lbest = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (lbest != -1) best = max(best, seg.query(lbest, i - 1));

        seg.update(i, best + 1);
    }

    cout << seg.query(0, n - 1) << "\n";
    return 0;
}
