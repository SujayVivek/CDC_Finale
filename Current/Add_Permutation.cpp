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
    int n, k; cin>>n>>k;
    if(k==n){
        for(int i = 1; i<=n; i++){
            cout<<i<<" ";
        }cout<<endl; return;
    }
    vi v(n+1, 0);
    if(k%2==0){
        int l = n-1;
        for(int i = 1; i<=n-1; i++){
            v[i] = l;
            l--;
        }
        v[n] = n;

        int t = k/2 - 1;
        int last = n;
        for(int i = 1; i<=t; i++){
            swap(v[i], v[last - i]);
        }
    }else{
        int l = n;
        for(int i = 1; i<=n; i++){
            v[i] = l;
            l--;
        }
        int t = (k-1)/2;
        int last = n+1;
        for(int i = 1; i<=t; i++){
            swap(v[i], v[last - i]);
        }
    }
    for(int i = 1; i<=n; i++) cout<<v[i]<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}