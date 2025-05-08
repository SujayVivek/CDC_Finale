#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void Solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;
    int min_changes = LLONG_MAX;
    string best_ans;
    for (int k = 1; k <= 26; ++k) {
        if (n % k != 0) continue;
        int target = n / k;
        vector<pair<int, int>> count;
        for (int i = 0; i < 26; ++i)
            count.emplace_back(freq[i], i);
        sort(count.rbegin(), count.rend());  
        vector<int> needed(26, 0);
        for (int i = 0; i < k; ++i)
            needed[count[i].second] = target;
        vector<int> current_needed = needed;
        string t = s;
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (current_needed[c] > 0) {
                current_needed[c]--;
            } else {
                t[i] = '#'; 
            }
        }
        int ptr = 0;
        for (int i = 0; i < n; ++i) {
            if (t[i] != '#') continue;
            while (ptr < 26 && current_needed[ptr] == 0) ++ptr;
            t[i] = 'a' + ptr;
            current_needed[ptr]--;
        }
        int changes = 0;
        for (int i = 0; i < n; ++i)
            if (t[i] != s[i]) ++changes;
        if (changes < min_changes) {
            min_changes = changes;
            best_ans = t;
        }
    }

    cout << min_changes << endl;
    cout << best_ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) Solve();
    return 0;
}
