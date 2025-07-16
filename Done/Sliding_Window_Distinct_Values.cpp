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

    set<int> st;
    map<int,int> mpp;
    vector<int> a(n);

    for(int i = 0; i<min(n,k); i++){
        cin>>a[i];
        mpp[a[i]]++;
        st.insert(a[i]);
    }

    vi ans;
    for(int i = k; i<n; i++){
        ans.push_back((int)st.size());

        cin>>a[i];
        mpp[a[i]]++;
        st.insert(a[i]);

        mpp[a[i-k]]--;
        if(mpp[a[i-k]]==0) st.erase(a[i-k]);
    }
    ans.push_back((int)st.size());
    for(auto x: ans) cout<<x<<" ";
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