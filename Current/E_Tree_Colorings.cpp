#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

const int MX = 500000;
const int INF = 1000000000;
static int spf[MX+1];
static int hdp[MX+1];

void precompute() {
    for (int i = 2; i <= MX; i++) {
        if (!spf[i]) {
            for (int j = i; j <= MX; j += i) if (!spf[j]) spf[j] = i;
        }
    }
    hdp[1] = 0;
    for (int x = 2; x <= MX; x++) {
        hdp[x] = INF;
        int tmp = x;
        vector<pair<int,int>> fac;
        while (tmp > 1) {
            int p = spf[tmp], c = 0;
            while (tmp % p == 0) {
                tmp /= p;
                c++;
            }
            fac.emplace_back(p, c);
        }
        vector<int> divs;
        function<void(int,int)> gen = [&](int i, int cur) {
            if (i == (int)fac.size()) {
                divs.push_back(cur);
                return;
            }
            auto &pr = fac[i];
            int p = pr.ff;
            int cnt = pr.ss;
            int val = cur;
            for (int e = 0; e <= cnt; e++) {
                gen(i+1, val);
                val *= p;
            }
        };
        gen(0, 1);
        for (int d : divs) {
            if (d >= 3) {
                int s1 = d - 2;
                int s2 = x / d;
                if (s1 >= 1 && hdp[s1] < INF && hdp[s2] < INF) {
                    hdp[x] = min(hdp[x], hdp[s1] + hdp[s2] + 1);
                }
            }
        }
    }
}

void Solve() {
    int m; cin >> m;
    int res = hdp[m];
    if (res >= INF) cout << -1;
    else cout << res+1;
    cout << endl;
}

int32_t main() {
    precompute();
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
