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
    int cnt = 0;
    for(int i = 0; i<n; i++){
        int dx, dy, x, y; cin>>dx>>dy>>x>>y;
        if(x==y && x+y==s){
            if(dx==-1 && dy==1) cnt++;
            else if(dx==1 && dy==-1) cnt++;
            else if(dx==-1 && dy==-1) cnt++;
            else if(dx==1 && dy==1) cnt++;
            continue;
        }
        if(x==y){
            if(dx==-1 && dy==-1) cnt++;
            else if(dx==1 && dy==1) cnt++;
        }else if(x+y==s){
            if(dx==-1 && dy==1) cnt++;
            else if(dx==1 && dy==-1) cnt++;
        }
    }
    cout<<cnt<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}