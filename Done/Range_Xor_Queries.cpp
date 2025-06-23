#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi a;
vi SegTree;

void build(int idx, int l, int r){
    if(l==r){
        SegTree[idx] = a[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*idx, l, mid);
    build(2*idx + 1, mid + 1, r);
    SegTree[idx] = SegTree[2*idx]^SegTree[2*idx +1];
}
int query(int idx, int lq, int rq, int l, int r){
    if(lq<=l && rq>=r){
        return SegTree[idx];
    }
    if(lq>r || rq<l){
        return 0;
    }
    int mid = (l+r)/2;
    return query(2*idx, lq, rq, l, mid)^query(2*idx + 1, lq, rq, mid + 1, r);
}
void Solve() {
    int n, q; cin>>n>>q;
    a.assign(n+1, 0);
    for(int i = 1; i<=n; i++) cin>>a[i];
    SegTree.assign(4*n +1, 0);
    build(1, 1, n);
    while(q--){
        int l, r; cin>>l>>r;
        cout<<query(1, l, r, 1, n)<<endl;
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