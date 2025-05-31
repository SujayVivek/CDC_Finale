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
    for(int i = 0; i<n; i++){
        st.insert(i+1);
    } vi a((n/2),0);
    for(int i = 0; i<(n/2); i++){
        cin>>a[i];
        st.erase(a[i]);
    }
    // cout<<st.size()<<endl;
    vi b(n/2, 0);
    for(int i = (n/2)-1; i>=0; i--){
        auto it = st.lower_bound(a[i]);
        if(it==st.begin()){
            cout<<-1<<endl; return;
        }it--;
        // cout<<*it<<endl;
        b[i] = *it; st.erase(it);
    }
    map<int,int> mpp;
    for(int i = 0; i<n/2; i++) mpp[b[i]]++, mpp[a[i]]++;
    for(auto it: mpp){
        if(it.second!=1){
            cout<<-1<<endl; return;
        }
    }
    for(int i = 0; i<n/2; i++){
        cout<<b[i]<<" "<<a[i]<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}