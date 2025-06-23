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
    vi a(2*n,0);
    for(int i = 0; i<n; i++) cin>>a[i];
    vi hash(n+1, 0);
    map<int,set<int>>mpp;
    map<int,set<int>>sec;
    vi mark(2*n, 0)
    for(int i = 0; i<2*n; i+=2){
        if(a[i]==a[i+1]  && a[i]<=n && hash[a[i]]==0) hash[a[i]]++, mark[i] = 1, mark[i+1] = 1;
    }
    for(int i = 0; i<2*n; i+=2){
        if(mark[i]) continue;
        if(hash[a[i]] && hash[a[i+1]]) sec[a[i]].insert(i);
        else if(hash[a[i]] || hash[a[i+1]]) mpp[a[i]].insert(i);
        else sec[a[i]].insert(i);
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