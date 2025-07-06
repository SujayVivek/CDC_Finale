#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Project {
    int st, en, m;
};
int32_t main() {
    int n;
    cin >> n;
    vector<Project> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i].st >> arr[i].en >> arr[i].m;
    sort(arr.begin(), arr.end(), [](Project &a, Project &b) { return a.en < b.en; });

    vector<int> dp(n);
    vector<int> ends;
    for (auto &p : arr) ends.push_back(p.en);

    dp[0] = arr[0].m;
    for (int i = 1; i < n; i++) {
        int l = upper_bound(ends.begin(), ends.end(), arr[i].st - 1) - ends.begin() - 1;
        dp[i] = max(dp[i - 1], arr[i].m + (l >= 0 ? dp[l] : 0));
    }
    cout << dp[n - 1] << endl;
    return 0;
}
