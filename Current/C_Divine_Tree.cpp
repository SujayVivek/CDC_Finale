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
    int n, m;cin >> n >> m;
    if (m<n || m>n*(n+1)/2) {
        cout <<-1<< endl; return;
    }
    int lo = 1, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        int ans = mid * (2 * n - mid + 1) / 2;
        if (ans >= m) hi = mid;
        else lo = mid + 1;
    }
    int k = lo;
    int smin = n + k - 1;
    if (m < smin) {cout << -1 << endl;return;}
    if (k == 1) {
        cout << 1 << endl;
        for (int i= 2; i<= n; ++i) {
            cout << 1 << " " << i<< endl;
        }
        return;
    }
    int rem = m - smin;
    vector<bool> use(n + 1, false);
    int P = 0;
    if ((k-1) > 0) 
        P = min((n-k), rem / (k-1));
    
    rem -= P*(k-1);
    for (int i= n, cnt = P;; --i) {
        if(cnt<=0) break;
        if (i== k) continue;
        use[i] = true, --cnt;
    }
    for (int i= k - 1; i>= 2 && rem > 0; --i) {
        int w =i-1;
        if(w>rem) continue;
        if (w<=rem) {
            use[i]=true, rem-= w;
        }
    }
    vector<int> par(n + 1, 1);
    cout <<k<< endl;
    cout <<k<< " " << 1 << endl;
    for (int i= 2; i<= n; ++i) {
        if (i== k) continue;
        par[i] = use[i] ?k:1;
        cout << par[i]<<" "<<i<< endl;
    }
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
