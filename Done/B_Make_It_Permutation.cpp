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
    cout <<2*n-1<<endl;
    for(int i = 1; i <= n; i++) {
        cout <<i<<" "<<1<<" "<<(n-i+1)<<endl;
        if(i>1) {
          cout<<i<<" "<<(n-i+2)<<" "<<n<<endl;
        }
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}