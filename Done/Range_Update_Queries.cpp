#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
vi a, SegTree, lazy;

void build(int idx, int l, int r){
    if(l==r){
        SegTree[idx] = a[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*idx , l, mid);
    build(2*idx +1, mid + 1, r);
}

void push(int idx, int l, int r){
    if(lazy[idx]==0) return;
    if(l<r){
        lazy[2*idx]+= lazy[idx];
        lazy[2*idx + 1]+= lazy[idx];
    }
    SegTree[idx]+= lazy[idx];
    lazy[idx] = 0;
}
void update(int idx, int lq, int rq, int l, int r, int val){
    push(idx, l, r);
    if(l>rq || r<lq) return;
    if(lq<=l && r<=rq){
        lazy[idx]+= val;
        push(idx, l, r);
        return;
    }
    int mid = (l +r)/2;
    update(2*idx, lq, rq, l, mid, val);
    update(2*idx + 1, lq, rq, mid + 1, r, val);
    
}

int query(int idx, int l, int r, int pos){
    push(idx, l, r);
    if(l>pos || r<pos) return 0;
    if(l==r) return SegTree[idx];
    int mid = (l + r)/2;
    return query(2*idx , l, mid, pos) + query(2*idx + 1, mid + 1, r, pos);
    // return query(2*idx + 1, mid + 1, r);

}
void Solve() {
    int n; cin>>n; int q; cin>>q;

    a.assign(n+1, 0);
    SegTree.assign(4*n +1, 0);
    lazy.assign(4*n +1, 0);
    for(int i = 1; i<=n; i++) cin>>a[i];
    build(1, 1, n);
    while(q--){
        int a; cin>>a;
        if(a==1){
            int l, r, v; cin>>l>>r>>v;
            update(1, 1, n, l, r, v);
        }else{
            int k; cin>>k;
            cout<<query(1,1,  n, k)<<endl;
        }
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