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
    vi a(n,0);  map<int,int>mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i]; mpp[a[i]]++;
    }vector<pair<int,int>>vp;
    for(auto it: mpp){
        vp.push_back({it.first, it.second});
    } 
    int pos = -1, choice = 4;
    for(auto it: vp){
        int v = it.first, cnt = it.second;
        if(v!=pos || choice ==4){
            pos = v+1;
            if(cnt>=4){
                cout<<"Yes"<<endl; return;
            }
            else if(cnt>=2){
                choice = 2;
            }else{
                choice = 4;
            }
        }else{
            pos = v+1;
            if(cnt>=2){
                cout<<"Yes"<<endl; return;
            }
            else if(cnt>=1){
                choice = 2;
            }
            else{
                choice = 4;
            }
        }
    }
    cout<<"No"<<endl; return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}