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
    int k, a, b, x, y; cin>>k>>a>>b>>x>>y;
    int ans = 0;
    if(x<=y){
        if(k>=a){
            int dif = k-a+1;
            int cnt = (dif+x-1)/x;
            ans+= cnt;
            k-= cnt*x;
        }
        if(k>=b){
            int dif = k-b+1;
            int cnt = (dif+y-1)/y;
            ans+= cnt;
            k-=cnt*y;
        }
    }else{
        if(k>=b){
            int dif = k-b+1;
            int cnt = (dif+y-1)/y;
            ans+= cnt;
            k-=cnt*y;
        }
        if(k>=a){
            int dif = k-a+1;
            int cnt = (dif+x-1)/x;
            ans+= cnt;
            k-= cnt*x;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}