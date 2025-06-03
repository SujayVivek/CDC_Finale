#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int fib[11];
void Solve() {
    int n, m; cin>>n>>m;
    int box1 = fib[n], box2 = fib[n-1]; int box3 = -1;
    if(n>2) box3 = fib[n-2];
    for(int i = 0; i<m; i++){
        vi a(3, 0);
        for(int j = 0; j<3; j++) cin>>a[j];
        sort(a.begin(), a.end());
        bool ok = true;
        if(box1>a[0]) ok = false;
        if(box1+box2>a[2]) ok = false;
        if(box3!=-1 && box2+box3>a[1]) ok = false;
        if(ok)cout<<1;
        else cout<<0;
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    fib[1] = 1, fib[2] = 2;
    for(int i = 3; i<=10; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    while (tt_--) {
        Solve();
    }
    return 0;
}