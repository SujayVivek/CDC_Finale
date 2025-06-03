#include <bits/stdc++.h>
using namespace std;

void Solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    // ops[k] holds indices of operations for mapping (i->j), where k = i*3 + j
    vector<set<int>> ops(9);

    // read operations
    for (int i = 1; i <= q; i++) {
        char xc, yc;
        cin >> xc >> yc;
        int u = xc - 'a';
        int v = yc - 'a';
        ops[u*3 + v].insert(i);
    }

    string ans = s;
    for (int pos = 0; pos < n; pos++) {
        int u = s[pos] - 'a';
        // try to convert s[pos] to a smaller letter v (< u)
        for (int v = 0; v < u; v++) {
            // check direct u->v
            int directBest = INT_MAX;
            if (!ops[u*3 + v].empty()) {
                directBest = *ops[u*3 + v].begin();
            }
            // check via one intermediate w
            int viaBest = INT_MAX, wChoice = -1, firstIdx = -1;
            for (int w = 0; w < 3; w++) {
                if (w == u || w == v) continue;
                if (ops[u*3 + w].empty() || ops[w*3 + v].empty()) continue;
                int idx1 = *ops[u*3 + w].begin();
                auto it = ops[w*3 + v].upper_bound(idx1);
                if (it == ops[w*3 + v].end()) continue;
                int idx2 = *it;
                if (idx2 < viaBest) {
                    viaBest = idx2;
                    wChoice = w;
                    firstIdx = idx1;
                }
            }
            // choose direct if possible
            if (directBest < INT_MAX) {
                ops[u*3 + v].erase(directBest);
                ans[pos] = char('a' + v);
                break;
            }
            // else choose via-w if possible
            if (viaBest < INT_MAX) {
                ops[u*3 + wChoice].erase(firstIdx);
                ops[wChoice*3 + v].erase(viaBest);
                ans[pos] = char('a' + v);
                break;
            }
            // otherwise, can't convert to v, try next v
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
