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
    int w, h, a, b; cin>>w>>h>>a>>b;
    int x1, x2, y1, y2; cin>>x1>>y1>>x2>>y2;
    bool ok = false;
    if((abs(x1-x2)%a)==0 && x1!=x2) ok = true;
    if((abs(y1-y2)%b)==0 && y1!=y2) ok = true;
    if(ok)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}