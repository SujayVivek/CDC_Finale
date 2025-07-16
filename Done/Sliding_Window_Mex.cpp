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

    set<int> missing;
    map<int,int> mpp;

    for(int i = 1; i<=k+2; i++){
        missing.insert(i-1);
    }//initially all are missing

    vector<int> a(n);
    for(int i = 0; i<k; i++){
        cin>>a[i];
        mpp[a[i]]++;
        auto it = missing.find(a[i]);
        if(it!=missing.end()) missing.erase(it);
    }
    cout<<*missing.begin()<<" ";

    for(int i = k; i<n; i++){
        cin>>a[i];
        mpp[a[i-k]]--;
        if(mpp[a[i-k]]==0){
            missing.insert(a[i-k]);
        }
        mpp[a[i]]++;
        auto it = missing.find(a[i]);
        if(it!=missing.end()) missing.erase(it);
        cout<<*missing.begin()<<" ";
    }
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}