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
    int L = 1; int temp = k; set<int> st;
    for(int i = n; i>=1; i--){
        if(!st.count(i))cout<<i<<" ";
        temp--;
        st.insert(i);
        if(temp==1){
            if(!st.count(L))cout<<L<<" "; st.insert(L); temp = k; L++;
        }
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