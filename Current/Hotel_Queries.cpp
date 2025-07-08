#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vector<pair<int,int>> SegTree;
vi h, g;

void build(int idx, int l, int r){
    if(l==r){
        SegTree[idx] = {h[l], l};
        return;
    }
    int mid = (l +r)/2;
    build(2*idx, l, mid);
    build(2*idx + 1, mid+1, r);
    SegTree[idx] = max(SegTree[2*idx], SegTree[2*idx+1]);
}

void update(int idx, int l, int r, int pos, int val){
    if(l>pos || r<pos) return;
    if(l==r && l==pos){
        SegTree[idx].first = val;
        return;
    }
    int mid = (l + r)/2;
    update(2*idx, l, mid, pos, val);
    update(2*idx +1, mid + 1, r, pos, val);
    SegTree[idx] = max(SegTree[2*idx], SegTree[2*idx+1]);
}
pair<int,int> query(int idx, int l, int r, int lq, int rq){
    if(l>rq || r<lq) return {0,0};
    if(l>=lq && r<=rq) return SegTree[idx];
    int mid = (l +r)/2;
    return max(query(2*idx, l, mid, lq, rq), query(2*idx + 1, mid + 1, r, lq, rq));
}
void Solve() {
    int n, m; cin>>n>>m;
    h.assign(n+1, 0);
    g.assign(m+1, 0);

    for(int i = 1; i<=n; i++) cin>>h[i];
    for(int i = 1; i<=m; i++) cin>>g[i];

    SegTree.assign(4*n+1, {});
    build(1, 1, n);

    for(int i = 1; i<=m; i++){
        int grpSz = g[i];

        int lo = 1, hi = n,ans = -1, ansPos = -1;
        while(lo<=hi){
            int mid = (hi - lo)/2 + lo;
            auto q = query(1, 1, n, 1, mid);
            if(q.first>=grpSz){
                ansPos = q.second;
                ans = q.first;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        if(ansPos==-1){
            cout<<0<<" "; continue;
        }
        cout<<ansPos<<" ";
        update(1, 1, n, ansPos, ans-grpSz);
    }
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