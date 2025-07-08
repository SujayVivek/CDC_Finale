#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi nums, SegTree, lazy;

void build(int idx, int l, int r){
    if(l==r){
        SegTree[idx] = nums[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*idx, l, mid);
    build(2*idx + 1, mid + 1, r);
}
void push(int idx, int l, int r){
    if(lazy[idx]!=0){
        SegTree[idx]+= lazy[idx];
        if(l!=r){
            lazy[2*idx]+= lazy[idx];
            lazy[2*idx + 1]+= lazy[idx];
        }
        lazy[idx] = 0;
    }
}

void update(int idx, int l, int r, int ul, int ur, int val){
    push(idx, l, r);
    if(l>ur || r<ul){
        return;
    }
    if(l>=ul && r<=ur){
        lazy[idx] += val;
        push(idx, l, r);
        return;
    }
    int mid = (l + r)/2;
    update(2*idx, l, mid, ul, ur, val);
    update(2*idx + 1, mid + 1, r, ul, ur, val);
}

int query(int idx, int l, int r, int pos){
    push(idx, l, r);
    if(l>pos || r<pos) return 0;
    if(l==r && l==pos){
        return SegTree[idx];
    }
    int mid = (l + r)/2;
    if(pos<=mid) return query(2*idx, l, mid, pos);
    else return query(2*idx +1, mid + 1, r, pos);
}

void Solve() {
    int n, q; cin>>n>>q;
    nums.assign(n+1, 0);
    for(int i = 1; i<=n; i++) cin>>nums[i];

    SegTree.assign(4*n+1, 0), lazy.assign(4*n +1, 0);
    build(1, 1, n);
    while(q--){
        int c; cin>>c;
        if(c==1){
            int u, v, val; cin>>u>>v>>val;
            update(1, 1, n, u, v, val);
        }else{
            int pos; cin>>pos;
            cout<< query(1, 1, n, pos)<<endl;
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