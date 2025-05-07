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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());  

    vi freq(n, 0); 
    vector<pair<int, int>> LR; 

    while(q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        LR.push_back({l, r});
        freq[l]++;
        if(r + 1 < n) freq[r + 1]--;
    }
    for(int i = 1; i < n; i++) {
        freq[i] += freq[i - 1];
    }
    vector<pair<int, int>> vp;
    for(int i = 0; i < n; i++) {
        vp.push_back({freq[i], i});
    }
    sort(vp.begin(), vp.end()); 
    reverse(a.begin(), a.end());
    vi assigned(n, 0);
    for(int i = 0; i < n; i++) {
        assigned[vp[n - 1 - i].second] = a[i];
    }
    for(int i = 1; i < n; i++) {
        assigned[i] += assigned[i - 1];
    }
    int totalSum = 0;
    for(auto it: LR) {
        int r = it.second, l = it.first;
        totalSum += assigned[r];
        if(l > 0) totalSum -= assigned[l - 1];
    }

    cout << totalSum << endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
