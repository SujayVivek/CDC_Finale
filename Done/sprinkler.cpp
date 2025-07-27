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
vi subTree;
int mx, S;
int cnt;
vector<int> factor(int x){
    vector<int> ans;
    for(int i = 1; i*i<=x; i++){
        if(x%i==0){
            ans.push_back(i);
            if(i*i!=x) ans.push_back(x/i);
        }
    }
    return ans;
}

void dfs(int node, int prev, int f){
    subTree[node] = nums[node];
    for(auto nn: g[node]){
        if(nn==prev) continue;
        dfs(nn, node, f);
        subTree[node]+= subTree[nn];
    }
    if(subTree[node]==f){
        cnt++;
        subTree[node] = 0;
    }
}
void Solve() {
    int n; cin>>n;
    g.assign(n+1, {}), nums.assign(n+1, 0);
    subTree.assign(n+1, 0);
    for(auto &x: nums) cin>>x;
    for(int i = 0; i<n-1; i++){
        int u, v; cin>>u>>v;
        g[u].push_back(v), g[v].push_back(u);
    }
     S = accumulate(nums.begin(), nums.end(), 0);
     mx = *max_element(nums.begin(), nums.end());

    vector<int> f = factor(S);
    sort(f.begin(), f.end());
    int res = -1;
    for(auto ff : f){
        if(ff<S/n) continue;
        cnt = 0;
        dfs(1, -1, ff);
        if(cnt>=S/n){
            res = ff;
            break;
        }
    }
    cout<<res<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}