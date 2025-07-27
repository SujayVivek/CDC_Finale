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
    vector<int> a(n,0);
    for(int i = 0; i<n; i++) cin>>a[i];
    int l = 0, r = n-1;
    while(l<r){
        if(l%2==0){
            if(a[l]>a[r]){
                cout<<"LR";
                l++;r--;
            }else{
                cout<<"RL";
                l++;r--;
            }
        }else{
            if(a[l]<a[r]){
                cout<<"LR";
                l++;r--;
            }else{
                cout<<"RL";
                l++;r--;
            }
        }
    }
    if(l==r)cout<<"L";
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