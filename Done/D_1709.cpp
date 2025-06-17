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
    vi a(n,0), b(n,0);
    for(auto &x: a) cin>>x;
    for(auto &x: b) cin>>x;
    vector<pair<int,int>> ans;
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                ans.push_back({1, j+1});
                swap(a[j], a[j+1]);
            }
        }
    }
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(b[j]>b[j+1]){
                ans.push_back({2, j+1});
                swap(b[j], b[j+1]);
            }
        }
    }
    for(int i = 0; i<n; i++){
        if(a[i]>b[i]){
            ans.push_back({3, i+1});
            swap(a[i], b[i]);
        }
    }
        for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                ans.push_back({1, j+1});
                swap(a[j], a[j+1]);
            }
        }
    }
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(b[j]>b[j+1]){
                ans.push_back({2, j+1});
                swap(b[j], b[j+1]);
            }
        }
    }
    // cout<<"HI"<<endl;
    // for(int i = 0; i<n; i++){
    //     cout<<a[i]<<" "<<b[i]<<endl;
    // } cout<<endl;
    cout<<ans.size()<<endl;
    for(auto it: ans){
        cout<<it.first<<" "<<it.second<<endl;
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