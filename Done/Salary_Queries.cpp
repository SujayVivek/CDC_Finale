#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

ll combine(ll a, ll b) { return a + b; }

template <class T>
class SegmentTree {
public:
    SegmentTree(vector<T> &data, T value, T (*combine)(T, T)) {
        this->combine = combine;
        valueForExtraNodes = value;
        n = data.size();
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size, valueForExtraNodes);
        for (int i = 0; i < n; ++i) tree[size + i] = data[i];
        for (int i = size - 1; i > 0; --i)
            tree[i] = combine(tree[2 * i], tree[2 * i + 1]);
    }
    void update(int idx, T val) {
        idx += size;
        tree[idx] = val;
        while (idx > 1) {
            idx >>= 1;
            tree[idx] = combine(tree[2 * idx], tree[2 * idx + 1]);
        }
    }
    T query(int l, int r) { 
        l += size; r += size;
        T resl = valueForExtraNodes, resr = valueForExtraNodes;
        while (l <= r) {
            if (l % 2 == 1) resl = combine(resl, tree[l++]);
            if (r % 2 == 0) resr = combine(tree[r--], resr);
            l >>= 1; r >>= 1;
        }
        return combine(resl, resr);
    }
private:
    vector<T> tree;
    int n, size;
    T valueForExtraNodes;
    T (*combine)(T, T);
};

int main() {
    fastio;
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    vector<pair<char, pair<ll, ll>>> queries(q);
    set<ll> vals;
    for (auto &x : a) { cin >> x; vals.insert(x); }
    for (auto &qr : queries) {
        cin >> qr.first >> qr.second.first >> qr.second.second;
        vals.insert(qr.second.second);
        if (qr.first == '?') vals.insert(qr.second.first);
    }
    vector<ll> comp(vals.begin(), vals.end());
    unordered_map<ll, ll> idx;
    for (ll i = 0; i < comp.size(); ++i) idx[comp[i]] = i;
    vector<ll> freq(comp.size(), 0);
    for (auto &x : a) ++freq[idx[x]];
    SegmentTree<ll> seg(freq, 0, combine);
    for (auto &qr : queries) {
        if (qr.first == '?') {
            ll l = idx[qr.second.first], r = idx[qr.second.second];
            cout << seg.query(l, r) << "\n";
        } else {
            ll pos = qr.second.first - 1;
            ll oldval = idx[a[pos]];
            ll newval = idx[qr.second.second];
            --freq[oldval];
            ++freq[newval];
            seg.update(oldval, freq[oldval]);
            seg.update(newval, freq[newval]);
            a[pos] = qr.second.second;
        }
    }
    return 0;
}
