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
    vi div;
    for(int i = 1; i*i<=n; i++){
        if(n%i==0) {
            div.push_back(i);
            if(i*i!=n) div.push_back(n/i);
        }
    }
    int o = 0;
    for(int i = 0; i<div.size(); i++) if(div[i]%2==1) o++;
    cout<< o<<" "<<(int)div.size()-o<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}