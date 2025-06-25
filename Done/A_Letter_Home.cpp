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
    int n, s; cin>>n>>s;
    vi a(n, 0);
    for(auto &x: a) cin>>x;
    sort(a.begin(), a.end());
    cout<<min(a.back()-a.front() + abs(s-a.back()), a.back()-a.front() + abs(s-a.front()))<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}