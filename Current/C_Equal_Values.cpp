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
    set<int> st;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    int mn = 1e18;
    vector<pair<int,int>>v;
    int i = 0, j = 0;
    if(st.size()==1){ cout<<0<<endl; return;}
    while(i<n && j<n){
        j = i+1; 
        int cnt = 1;
        while(a[j]==a[i] && j<n){
            cnt++; j++;
        }
        v.push_back({a[i], cnt});
        i = j;
    }
   
    for(int i = 0; i<v.size(); i++){
        int ans = v[i].first*i + (n-v[i].second-i)*(v[i].first);
        mn = min(ans, mn);
    }
    cout<<mn<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}