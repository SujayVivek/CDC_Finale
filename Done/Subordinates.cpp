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
vi nums;

void dfs(int node, int prev){
    nums[node] =1;
    for(auto nn: g[node]){
        if(nn==prev) continue;
        dfs(nn, node);
        nums[node]+= nums[nn];
    }
}
void Solve() {
    int n; cin>>n;
    g.assign(n+1, {});
    for(int i = 2; i<=n; i++){
        int x; cin>>x;
        g[x].push_back(i);
    }
    nums.assign(n+1, 0);
    dfs(1, -1);
    for(int i = 1; i<=n; i++) cout<< nums[i] - 1<<" ";
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