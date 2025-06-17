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
    int n, k; cin >> n >> k;
    vi p(n, 0), d(n, 0);
    for(auto &x: p) cin>>x;
    for(auto &x: d) cin>>x;
    vi nxt(2*n*k, -2); vvi rev(2*n*k); vi ok(2*n*k, 0);
    for (int i = 0; i < n; i++) {
        for (int dir = 0; dir < 2; dir++) {
            for (int r = 0; r < k; r++) {
                int cur = (i*2+dir)*k+r,  go = dir;
                if (r == d[i]) go ^= 1;
                int pos = (go == 1 ? i + 1 : i - 1);
                if (pos < 0 || pos >= n) nxt[cur] = -1;
                else {
                    int dist = abs(p[pos] - p[i]) % k, nr = (r + dist) % k, to = (pos * 2 + go) * k + nr;
                    nxt[cur] = to;
                }
            }
        }
    }
    queue<int> q;
    for (int i = 0; i < 2*n*k; i++) {
        int to = nxt[i];
        if (to == -1) ok[i] = 1, q.push(i);
        else rev[to].push_back(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : rev[u]) {
            if (!ok[v]) {
                ok[v] = 1, q.push(v);
            }
        }
    }
    int Q;cin>>Q;
    while(Q--){
        int a;cin >> a;
        int idx =lower_bound(p.begin(), p.end(), a) - p.begin();
        if (idx== n) {
            cout<<"YES"<<endl;
        } else {
            int dist = (p[idx] - a) % k, st = (idx * 2 + 1)*k + dist;
            if(ok[st])cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}