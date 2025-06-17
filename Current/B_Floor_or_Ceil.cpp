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
    int x, n, m; cin>>x>>n>>m;
    int cx = x, cy = x;
    for(int i = 0; i<n && cx>0; i++){
        cx/=2;
    }
    for(int i = 0; i<m && cx>0; i++){
        cx = (cx +1)/2;
        if(cx == 1) break;
    }
    for(int i = 0; i<m && cy>0; i++){
        cy = (cy+1)/2;
        if(cy == 1) break;
    }
    for(int i = 0; i<n && cy>0; i++)
    {
        cy  = cy/2;
    }
    cout<<cy<<" "<<cx<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}