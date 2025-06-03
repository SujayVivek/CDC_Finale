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
    vi a(n,0); int gcd = 0;
    map<int,int> mpp;
    set<int> st;
    for(int i = 0; i<n; i++){
        cin>>a[i]; gcd = __gcd(a[i], gcd);
        mpp[a[i]]++;
        st.insert(a[i]);
    }
    if(mpp[gcd]!=0){
        cout<<n-mpp[gcd]<<endl;
    }else{
        vi v; int mx = 0;
        for(auto it: st){
            v.push_back(it);
            mx = max(mx, it);
        }
        vi dist(mx + 1, 1e18);
        queue<int> q;
        for(int i = 0; i<v.size(); i++){
            q.push(v[i]); dist[v[i]] = 0;
        }
        while(!q.empty()){
            int top = q.front(); q.pop();
            for(int i = 0; i<v.size(); i++){
                int G = __gcd(top, v[i]);
                if(dist[G]> 1+ dist[top]){
                    dist[G] = 1+ dist[top];
                    q.push(G);
                }
            }
        }
        int cnt = dist[gcd];
        cout<<n-1+cnt<<endl;
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}