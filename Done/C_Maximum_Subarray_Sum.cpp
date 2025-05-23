#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int inf = 1e6; 

long long kadane(const vector<long long>& a) {
    long long best = 0, pre = 0;
    for (auto x : a) {
        pre = max(pre + x, x);
        best = max(best, pre);
    }
    return best;
}
void Solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int j = s.find('0');
    if (j != -1) {
        long long lb = 0, rb = 0, sum = 0;
        for (int i = j + 1; i < n && s[i] == '1'; ++i) {
            sum += a[i];
            rb = max(rb, sum);
        }
        sum = 0;
        for (int i = j - 1; i >= 0 && s[i] == '1'; --i) {
            sum += a[i];
            lb = max(lb, sum);
        }
        a[j] = k - lb - rb;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0' && i != j) {
                a[i] = -inf;
            }
        }
    }

    if (kadane(a) != k) {
        cout << "No" << "\n";
        return;
    }

    cout << "Yes" << "\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        Solve();
    }

    return 0;
}
