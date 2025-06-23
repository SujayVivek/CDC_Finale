#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

bool check(int l1, int b1, int l2, int b2, int l3, int b3) {
    int area = l1*b1 + l2*b2 + l3 * b3;
    // cout<<area<<endl;
    int S = sqrt(area);
    if (sqrt(area) * sqrt(area) != area) return false;
    return (l1 == S && l2 == S && l3 == S && b1 + b2 + b3 == S) ||(b1 == S && b2 == S && b3 == S && l1 + l2 + l3 == S) ||(l1 == S && b1 < S && b2 == S - b1 && b3 == S - b1 && l2 + l3 == S) ||(b1 == S && l1 < S && l2 == S - l1 && l3 == S - l1 && b2 + b3 == S);
}

void Solve() {
    int l1,b1,l2,b2,l3,b3; cin >>l1>>b1>>l2>>b2>>l3>>b3;
    if (check(l1, b1, l2, b2, l3, b3)){cout<<"YES"<<endl; return;}
    cout<<"NO"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
