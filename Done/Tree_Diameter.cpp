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
    vvi g;
    int n; cin>>n;
    if(n==1){cout<<0<<endl; return;}
    g.assign(n+1, {});
    for(int i = 0; i<n-1; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b), g[b].push_back(a);
    }
    vi dist(n+1, 1e18);
    dist[1] = 0;
    int A = -1, mxA = -1;
    queue<int> q; q.push(1);
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto nn: g[node]){
            if(dist[nn]>dist[node] + 1){
                q.push(nn);
                dist[nn] = 1 + dist[node];
                if(mxA<dist[nn]){
                    mxA = dist[nn];
                    A = nn;
                }
            }
        }
    }
    dist.assign(n+1, 1e18);
    q.push(A);
    dist[A] = 0;
    int mxB = -1;
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto nn: g[node]){
            if(dist[nn]>dist[node] + 1){
                dist[nn] = 1 + dist[node];
                q.push(nn);
                if(mxB<dist[nn]){
                    mxB = dist[nn];
                    // B = nn;
                }
            }
        }
    }
    cout<<mxB<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}