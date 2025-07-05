#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n, m;
vi num;
vvi dp;

int calc(int i, int last) {
    if (i == n) return 1;

    int &res = dp[i][last];
    if (res != -1) return res;
    long long ways = 0;

    if (num[i] == 0) {
        for (int d = -1; d <= 1; d++) {
            int cur = last + d;
            if (cur >= 1 && cur <= m) {
                ways = (ways + calc(i + 1, cur)) % mod;
            }
        }
    } else {
        int cur = num[i];
        if (abs(cur - last) <= 1) {
            ways = calc(i + 1, cur);
        }
    }
    return res = ways;
}

void Solve() {
    cin >> n >> m;
    num.assign(n, 0);
    for (int i = 0; i < n; i++) cin >> num[i];
    dp.assign(n, vi(m+1, -1));

    long long answer = 0;

    if (num[0] == 0) {
        for (int start = 1; start <= m; start++) {
            answer = (answer + calc(1, start)) % mod;
        }
    } else {
        answer = calc(1, num[0]);
    }
    
    cout << answer << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();
    return 0;
}
