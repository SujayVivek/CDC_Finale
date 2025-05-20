#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long

int modinv(int a, int m) {
    int m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while (a > 1) {
        int q = a / m;
        int t = m;
        m = a % m; a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

void Solve() {
    int n, m; cin >> n >> m;
    map<int, int> freq;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (freq[x] == 0) a.push_back(x);
        freq[x]++;
    }
    if (a.size() < m) {
        cout << 0 << endl;
        return;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int prod = 1;
    for (int i = 0; i < m - 1; ++i)
      prod = (prod * freq[a[i]]) % mod;
    for (int i = 0; i + m - 1 < a.size(); ++i) {
        if (i > 0) {
            prod = (prod * modinv(freq[a[i - 1]], mod)) % mod;
            prod = (prod * freq[a[i + m - 1]]) % mod;
        } else {
            prod = (prod * freq[a[m - 1]]) % mod;
        }
        if (a[i + m - 1] - a[i] < m) {
            ans = (ans + prod) % mod;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        Solve();
    }
    return 0;
}
