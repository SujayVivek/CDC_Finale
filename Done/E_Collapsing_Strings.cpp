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
    int n; cin >> n;
    vi freq(26, 0), sum(26, 0);
    vector<string> vs;
    int S = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        freq[s[0] - 'a']++;
        sum[s[0] - 'a'] += s.length();
        S += s.length();
        vs.push_back(s);
    }
    int Ans = 0;
    for (int i = 0; i < n; i++) {
        string s = vs[i];
        char last = s.back();
        int idx = last - 'a';
        Ans += (s.length()-2)*freq[idx] + sum[idx];
        Ans += s.length()*(n-freq[idx]) + (S - sum[idx]);
    }
    cout << Ans << endl;
}


int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}