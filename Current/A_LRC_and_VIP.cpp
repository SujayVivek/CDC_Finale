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
    set<int> st;
    vector<pair<int,int>>a(n);
    for(int i = 0; i<n; i++){
        int x; cin>>x;
        a[i] = {x, i};
        st.insert(x);
    }
    if(st.size()==1){
        cout<<"No"<<endl; return;
    }
    cout<<"Yes"<<endl;
    sort(a.begin(),a.end());
    vi ans(n, 0);
    for(int i = 0; i<n-1; i++){
        ans[a[i].second] = 1;
    }
    ans[a[n-1].second] = 2;
    for(auto x: ans)cout<<x<<" ";
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