#include <bits/stdc++.h>
using namespace std;
#define int long long
using vi = vector<int>;
using vvi = vector<vi>;

void Solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto &x : a) cin >> x, --x;

    vvi g(n);
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    string res(n, '0');
    for (int u = 0; u < n; ++u) {
        map<int, int> freq;
        ++freq[a[u]];
        for (int v : g[u]) ++freq[a[v]];
        for (auto it : freq) {
            int cnt = it.second, val = it.first;
            if (cnt >= 2) res[val] = '1';
        }
    }

    cout << res << '\n';
}

int32_t main() {
    int T; cin >> T;
    while (T--) Solve();
    return 0;
}
