#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
vi segTree;
vi nums;

void build(int idx, int l, int r){
    if(l==r){
        segTree[idx] = nums[l];
        return;
    }
    int mid = (l + r)/2;
    build(2*idx, l, mid);
    build(2*idx + 1, mid + 1, r);
    segTree[idx] = 
}
void Solve() {
    int n, q; cin>>n>>q;
    nums.assign(n+1, 0);
    segTree.assign(4*n+1, 0);
    for(int i = 1; i<=n; i++) cin>>nums[i];
    while(q--){

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