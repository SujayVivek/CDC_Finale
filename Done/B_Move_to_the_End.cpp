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
    int n; cin>>n;
    vi a(n,0);
    for(auto &x: a) cin>>x;
    multiset<int> ms;
    for(int i = 0; i<n; i++) ms.insert(a[i]);
    int j = 0;
    vi suff(n+1,0);  
    for(int i = n-1; i>=0; i--) suff[i]+= suff[i+1] + a[i];
    for(int j = n-1; j>=0; j--){
        auto it = ms.rbegin();
        if(a[j]<*it){
            cout<<suff[j+1] + *it<<" ";
        }else{
            cout<<suff[j+1] + a[j]<<" ";
        }
        auto it2 = ms.find(a[j]);
        ms.erase(it2);
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}