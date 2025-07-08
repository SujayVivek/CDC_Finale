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
vi SegTree;
vi euler, in, out, nums;
int timer;

void dfs(int node, int prev){
    in[node] = timer++;
    for(auto nn: g[node]){
        if(nn==prev) continue;
        dfs(nn, node);
    }
    out[node] = timer++;
}

void build(int idx, int l, int r){
    if(l==r){
        SegTree[idx] = euler[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*idx, l, mid);
    build(2*idx +1, mid + 1, r);
    SegTree[idx] = SegTree[2*idx] + SegTree[2*idx + 1];
}

void update(int idx, int l, int r, int pos, int val){
    if(l>pos || r<pos) return;
    if(l==r && l==pos){
        SegTree[idx] = val;
        return;
    }
    int mid = (l + r)/2;
    update(2*idx, l, mid, pos, val);
    update(2*idx + 1, mid +1, r, pos, val);
    SegTree[idx] = SegTree[2*idx] + SegTree[2*idx + 1];
}

int query(int idx, int l, int r, int lq, int rq){
    if(l>rq || r<lq) return 0;
    if(l>=lq && r<=rq){
        return SegTree[idx];
    }
    int mid = (l +r)/2;
    return query(2*idx, l, mid, lq, rq) + query(2*idx + 1, mid + 1, r, lq, rq);
}

void Solve() {
    int n, q; cin>>n>>q;
    nums.assign(n+1, 0);
    for(int i = 1; i<=n; i++) cin>>nums[i];

    g.assign(n+1, {});
    for(int i = 0; i<n-1; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b), g[b].push_back(a);
    }

    in.assign(n+1, 0), out.assign(n+1, 0);
    euler.assign(2*n+2, 0);
    timer = 1;
    dfs(1, -1);

    for(int i = 1; i<=n; i++){
        euler[in[i]] = nums[i];
        euler[out[i]] = -nums[i];
    }

    SegTree.assign(4*(2*n+2)+1, 0);
    build(1, 1, 2*n+1);

    while(q--){
        int c; cin>>c;
        if(c==1){
            int X; cin>>X; int V; cin>>V;
            update(1, 1, 2*n+1, in[X], V);
            update(1, 1, 2*n+1, out[X], -V);
            euler[in[X]] = V;
            euler[out[X]] = -V;
            nums[X] = V;
        }else{
            int X; cin>>X;
            cout<<query(1, 1, 2*n+1, 1, in[X])<<endl;
        }
    }
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}