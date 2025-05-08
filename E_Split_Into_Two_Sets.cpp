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
    int n; cin>>n; set<int> st, st1;bool ok = true;
    for(int i = 0; i<n; i++){
        int a, b; cin>>a>>b;
        if(a==b) ok = false;
        if(!st.count(a) &&  !st.count(b)){ st.insert(a), st.insert(b);}
        else if(!st1.count(a) && !st1.count(b)){ st1.insert(a), st1.insert(b);}
        else{
            ok = false;
        }
    }
    if(!ok){
        cout<<"NO"<<endl; return;
    }
    cout<<"YES"<<endl; return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}