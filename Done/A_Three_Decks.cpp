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
    int a, b, c; cin>>a>>b>>c;
    int S = a + b + c;
    if(S%3){cout<<"NO"<<endl; return;}
    S/=3;
    if(c-S< S-b + S-a || b>S){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
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