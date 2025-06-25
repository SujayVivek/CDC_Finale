#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
 
void Solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = 0;
    for (int k = 2; k < n; k++) {
        int T = max(a[k], a[n-1] - a[k]);
        int l = 0, r = k - 1;
        while (l < r) {
            if (a[l] + a[r] > T) {
                ans += (r - l), r--;
            } else {
                l++;
            }
        }
    }
    cout << ans << endl;
}
 
int32_t main() {
    int t;
    cin >> t;
    while (t--) Solve();
    return 0;
}