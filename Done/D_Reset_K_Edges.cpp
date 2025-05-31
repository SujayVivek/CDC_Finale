#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int moves = 0;
 
int dfs(int m,int node, int par,vector<vector<int>>& (g)){
    int sz = 1;
    for(auto x : g[node]){
        if(x==par)
            continue;
        sz = max(dfs(m,x,node,g)+1,sz);
    }
    if(sz==m && par!=0 && node!=0){
        moves++;
        return 0;
    }
    return sz;
}
 
int check(int m, vector<vector<int>>& (g),int k)
{
    moves = 0;
    if(m>1)
        dfs(m,0,-1,g);
    else
        moves = g.size()-1-g[0].size();
    return moves<=k;
}
bool Solve()
{
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    vector<vector<int>> g(n);
    for(int i=1,x ; i<n ; ++i){
        cin >> x;
        g[i].push_back(x-1);
        g[x-1].push_back(i);
    }
    int lo = 1, hi = n, ans = n;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid,g,k)){
            ans = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    cout << ans << endl;
    return true;    
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}