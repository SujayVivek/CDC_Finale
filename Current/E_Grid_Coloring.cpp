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
    int n, m;
    cin >> n >> m;
    int cx = (n + 1) / 2;
    int cy = (m + 1) / 2;
    vector<tuple<int,int,int,int>> cells;
    cells.reserve(n * m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int d1 = max(abs(i - cx), abs(j - cy));
            int d2 = abs(i - cx) + abs(j - cy);
            cells.emplace_back(d1, d2, i, j);
        }
    }
    sort(cells.begin(), cells.end());
    for (auto &t : cells) {
        cout << get<2>(t) << " " << get<3>(t) << endl;
    }cout<<endl;
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
