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
    vi a(n,0);
    for(int i = 0; i<n; i++) cin>>a[i];
    vi pref(n,0), suff(n,0); pref[0] = ((a[0]<k)?1:-1);
    for(int i = 1; i<n; i++){
        pref[i] = pref[i-1] + ((a[i]<k)?1:-1);
    }
    for(int i = n-1; i>=0; i--){
        suff[i] = ((a[i]<k)?1:-1);
        if(i!=n-1) suff[i]+= suff[i+1];
    }
    vi max_suff(n, 0), max_pref(n,0);
    for(int i = n-1; i>=0; i--){
        max_suff[i] = max(max_suff[i], pref[i]);
        if(i!=n-1) max_suff[i] = max(max_suff[i], pref[i]);
    }
    for(int i = 0; i<n; i++){
        max_pref[i] = max(max_pref[i], suff[i]);
        if(i) max_pref[i] = max(max_pref[i], max_pref[i-1]);
    }
    bool ok = false;
    for(int i = 0; i<n-1; i++){
        if(pref[i]>=0 && max_suff[i+1]>=0) ok = true;
    }
    for(int i = n-1; i>1; i--){
        if(suff[i]>=0 && max_pref[i-1]>=0) ok = true;
    }
    int x = 0, y = n-1;
    while(x <= n - 1 && pref[x] < 0) x++;
    while(y >= 0 && suff[y] < 0) y--;    
    if(y-x>=2) ok = true;
    if(ok){cout<<"YES"<<endl;}
    else cout<<"NO"<<endl;
}
 
int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}