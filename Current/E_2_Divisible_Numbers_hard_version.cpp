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
    int a, b, c, d; cin>>a>>b>>c>>d;
    vector<pair<int,int>> afac, bfac;
    for(int i = 1; i*i<=a; i++){
        if(a%i==0){
            afac.push_back({i, a/i});
            afac.push_back({a/i, i});
        }
    }
    for(int i = 1; i*i<=b; i++){
        if(b%i==0){
            bfac.push_back({i, b/i});
            bfac.push_back({b/i, i});
        }
    }
    // cout<<afac.size()<<endl;
    for(auto fac1: afac){
        for(auto fac2: bfac){
            int x = fac1.first*fac2.first;
            int y = fac1.second*fac2.second;
            int mul1 = (a)/x + 1, mul2 = (b)/y + 1;
            if(mul1*x<=c && mul2*y<=d){
                cout<<mul1*x<<" "<<mul2*y<<endl;
                return;
            }
        }
    }
    cout<<-1<<" "<<-1<<endl; return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}