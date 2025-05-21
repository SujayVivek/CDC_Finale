#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int t, tt_;
void Solve() {
    int n; cin>>n;
    string s; cin>>s;
    vi lps(n+1, 0);
    lps[0] = -1;
    int i = 0, j = -1;
    while(i<n){
        while(j!=-1 && s[i]!=s[j]) j = lps[j];
        i++; j++; lps[i] = j;
    }
    vector<pair<int,int>>vp;
    for(int i = 1; i<=n; i++){
        if(i%(i-lps[i])==0 && i/(i-lps[i])>1){
            vp.push_back({i, i/(i-lps[i])});
        }
    }
    cout<<"Test case #"<<t-tt_<<endl;
    for(auto it: vp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<endl;
}

int32_t main() {
    // int tt_ = 1;
    cin >> tt_;
    t = tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}