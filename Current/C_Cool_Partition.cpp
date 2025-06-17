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
    map<int,deque<int>>mpp;
    for(int i = 0; i<n; i++){
        cin>>a[i];
        mpp[a[i]].push_back(i);
    }
    int cnt = 1;
    set<int> st;
    st.insert(a[0]);
    mpp[a[0]].pop_front();
    int i= 1;
    while(i<n){
        int farthest = 0;
        bool ok = true;
        for(auto s: st){
            while (!mpp[s].empty() && mpp[s].front() < i)
                mpp[s].pop_front();
            if(mpp[s].size()==0){ok = false; break;}
            farthest = max(farthest, mpp[s].front());
            mpp[s].pop_front();
        }
        if(!ok) break;
        st.clear();
        int j = i;
        for( ; j<=farthest; j++){
            st.insert(a[j]);
        }
        cnt++;
        i = j;
    }
    cout<<cnt<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}