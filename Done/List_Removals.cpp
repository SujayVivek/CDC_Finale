#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi SegTree;
void build(int idx, int l, int r){
    if(l==r){
        SegTree[idx] = 1;
        return;
    }
    int mid = (l + r)/2;
    build(2*idx, l, mid);
    build(2*idx + 1, mid + 1, r);
    SegTree[idx] = SegTree[2*idx] + SegTree[2*idx + 1];
}
void update(int idx, int l, int r, int pos){
    if(l>pos || r<pos) return ;
    if(l==r && l==pos) {SegTree[idx] = 0; return;}
    int mid = (l + r)/2;
    update(2*idx, l, mid, pos);
    update(2*idx + 1, mid + 1, r, pos);
    SegTree[idx] = SegTree[2*idx] + SegTree[2*idx + 1];
}

int query(int idx, int l, int r, int lq, int rq){
    if(l>rq || r<lq) return 0;
    if(l>=lq && r<=rq) return SegTree[idx];
    int mid = (l + r)/2;
    return query(2*idx, l, mid, lq, rq) + query(2*idx + 1, mid + 1, r, lq, rq);
}
void Solve() {
    int n; cin>>n;
    vi p(n+1), q(n+1); 
    for(int i = 1; i<=n; i++) cin>>p[i];
    for(int i = 1; i<=n; i++) cin>>q[i];
    SegTree.assign(4*n+1, 0);
    build(1,1,n);
    for(int i = 1; i<=n; i++){
        int pos = q[i];
        int lo = 1, hi = n, ans = 1;
        while(lo<=hi){
            int mid = (lo + hi)/2;
            if(query(1, 1, n, 1, mid)>=pos){
                ans = mid;
                hi = mid - 1;
                // update(1, 1, n, mid);
            }else{
                lo = mid + 1;
            }
        }
        update(1, 1, n, ans);
        cout<<p[ans]<<" ";
    }cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}