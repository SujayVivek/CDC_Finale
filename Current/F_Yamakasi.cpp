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
    int n, s, x;cin >> n >> s >> x;
    vi a(n); for (auto &v : a) cin >> v;
    int ans = 0, i = 0;
    while (i< n) {
        if (a[i]>x) {++i;continue;}
        int L = i;
        while (i < n && a[i] <= x) ++i;
        int R = i - 1;
        unordered_map<int,int> freq;
        freq.reserve((R - L + 3) * 2);
        freq[0] = 1;
        int pref = 0, total = 0, sub = 0, j = L;
        for (int j = L; j <= R; ++j) {
            pref += a[j];
            // cout<<"HI "<<pref<<endl;
            auto it = freq.find(pref - s);
            if (it != freq.end()) total += it->second;
            // cout<<"tot = "<<total<<endl;
            ++freq[pref];
        }
        while (j <= R) {
            if (a[j] == x) { ++j;continue;} int start = j;
            while (j <= R && a[j] < x) ++j;
            int end = j - 1;
            freq.clear(),freq[0] = 1;
            pref = 0;
            for (int k = start; k <= end; ++k) {
                pref += a[k];
                auto it2 = freq.find(pref - s);
                if (it2 != freq.end()) total -= it2->second;
                // cout<<"tot = "<<total<<" sub = "<<sub<<endl;
                ++freq[pref];
            }
        }
        ans += total;
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
