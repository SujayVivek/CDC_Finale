#include <iostream>
#include <vector>
using namespace std;

int Sum(const vector<int>& v) {
    int s = 0;
    for (int i = 0; i < (int)v.size(); ++i)
        s += (v[i]&1);
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    if (!(cin >> a >> b)) return 0;
    int len = a.size();
    vector<int> u, v;
    u.reserve(len);
    v.reserve(len);
    for (int j = 0; j < len; ++j) {
        if (b[j] == '0') v.push_back(j);
    }
    for (int j = 0; j < len; ++j) {
        if (a[j] == '0') u.push_back(j);
    }
    int x = Sum(u) + Sum(v);

    int cnt = 0;

    if (u.size() != v.size()) {
        cout << -1 << "\n";
        return 0;
    }
    for (int i = 0; i < (int)u.size(); ++i) {
        if (u[i] != v[i]) cnt++;
    }

    cout << cnt << "\n";
    return 0;
}
