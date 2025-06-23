#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vvi g;
vi indegree;
void Solve() {
    int n; cin>>n;
    g.assign(n+1, {});
    indegree.assign(n+1, 0);
    for(int i = 1; i<=n; i++){
        int r; cin>>r;
        g[i].push_back(r);
        indegree[r]++;
    }
    deque<int> dq;
    for(int i = 1; i<=n; i++){
        if(indegree[i]==0) dq.push_back(i);
    }
    int cnt= 1;
    while(!dq.empty()){
        int temp = dq.size();
        while(temp--){
            int x = dq.front(); dq.pop_front();
            for(auto nn: g[x]){
                indegree[nn]--;
                if(indegree[nn]==0) dq.push_back(nn);
            }
        }
        cnt++;
    }cout<<cnt+1<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}