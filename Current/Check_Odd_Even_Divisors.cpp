#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

void Solve() {
    int A, B;
    cin >> A >> B;
    if (A >= 1 && B % A == 0) 
        cout << "Yes\n";
    else 
        cout << "No\n";
}

int32_t main() {
    int tt_;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
