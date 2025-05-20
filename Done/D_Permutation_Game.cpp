#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve() {
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;

    vector<int> p(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    auto getMaxScore = [&](int start) {
        int pos = start;
        int sum = 0, max_score = 0;
        for (int i = 0; i < k; i++) {
            sum += a[pos];
            int rem = (k - i - 1);
            max_score = max(max_score, sum + rem * a[pos]);
            if (p[pos] == pos) break;
            pos = p[pos];
        }
        return max_score;
    };
    int score_b = getMaxScore(pb);
    int score_s = getMaxScore(ps);
    if (score_b > score_s) cout << "Bodya\n";
    else if (score_b < score_s) cout << "Sasha\n";
    else cout << "Draw\n";
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) Solve();
    return 0;
}
