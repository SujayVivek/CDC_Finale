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
    string s; cin>>s;
    vvi nxt(k, vi(n+2, n+1));
    for(int x = 0; x<k; x++){
        for(int i = n-1; i>=0; i--){
            nxt[x][i] = s[i] == 'a' + x? i+1: nxt[x][i+1];
        }
    } vi f(n+2);
    for(int i = n; i>=0; i--){
        f[i] = 1e18;
        for(int x = 0; x<k; x++){
            f[i] = min(f[i], 1 + f[nxt[x][i]]);
        }
    }
    int q; cin>>q;
    while(q--){
        string t; cin>>t;
        int x = 0;
        for(auto c: t){
            x = nxt[c-'a'][x];
        }
        cout<<f[x]<<endl;
    }
    return ;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}