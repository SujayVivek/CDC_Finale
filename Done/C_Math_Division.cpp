#include <bits/stdc++.h>
using namespace std;

#define int long long
#define mod 1000000007

unordered_map<string, int> dp;
int inv2;
int modPow(int a, int b) {
    int res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
string divide_by_2(string s) {
    string res = "";
    int carry = 0;
    for (char c : s) {
        int num = carry * 2 + (c - '0');
        res += (num / 2) + '0';
        carry = num % 2;
    }
    size_t pos = res.find_first_not_of('0');
    return pos == string::npos ? "0" : res.substr(pos);
}
string ceil_divide_by_2(string s) {
    // Add 1 to s
    int n = s.size(), carry = 1;
    for (int i = n - 1; i >= 0 && carry; --i) {
        if (s[i] == '1') {
            s[i] = '0';
        } else {
            s[i] = '1';
            carry = 0;
        }
    }
    if (carry) s = '1' + s;
    return divide_by_2(s);
}

int solve(string s) {
    if (s == "1") return 0;
    if (dp.count(s)) return dp[s];

    string lo = divide_by_2(s);
    string hi = ceil_divide_by_2(s);

    int a = solve(lo);
    int b = solve(hi);

    int res = (a + b) % mod;
    res = res * inv2 % mod;
    res = (res + 1) % mod;
    return dp[s] = res;
}

void Solve() {
    int n;
    string s;
    cin >> n >> s;
    
    size_t pos = s.find_first_not_of('0');
    if (pos != string::npos)
        s = s.substr(pos);
    else
        s = "0";

    dp.clear();
    cout << solve(s) << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    inv2 = modPow(2, mod - 2);

    int t;
    cin >> t;
    while (t--) {
        Solve();
    }
    return 0;
}
