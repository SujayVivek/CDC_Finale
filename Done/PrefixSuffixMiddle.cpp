#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n; cin >> n; string s; cin >> s;
    vi lps(n+1, 0);
    lps[0] = -1;
    int i = 0, j = -1;
    while (i < n) {
        while (j != -1 && s[i] != s[j]) j = lps[j];
        ++i; ++j;lps[i] = j;
    }
    // 2) Mark which border‐lengths actually occur somewhere in the middle
    vector<bool> seen(n+1, false);
    for (int k = 1; k < n; ++k) {
        // any prefix ending before the last character
        // if lps[k] = L, it means the border of length L
        // occurs ending at position k-1
        seen[lps[k]] = true;
    }
    // 3) Walk down the border‐chain from the full‐length border
    int t = lps[n];  
    while (t > 0) {
        if (seen[t]) {
            // We have a border of length t that also appeared in the middle
            cout << s.substr(0, t) << endl;
            return;
        }
        // fallback to the next smaller proper border
        t = lps[t];
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
