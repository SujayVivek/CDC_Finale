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
    if(l == r){
        segTree[idx] = nums[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx, l, mid);
    build(2 * idx + 1, mid + 1, r);
    segTree[idx] = segTree[2 * idx] + segTree[2 * idx + 1];
}

void update(int idx, int l, int r, int pos, int val){
    if(pos < l || pos > r) return;
    if(l == r){
        segTree[idx] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * idx, l, mid, pos, val);
    update(2 * idx + 1, mid + 1, r, pos, val);
    segTree[idx] = segTree[2 * idx] + segTree[2 * idx + 1];
}

int query(int idx, int lq, int rq, int l, int r){
    if(l > rq || r < lq) return 0;
    if(lq <= l && r <= rq) return segTree[idx];
    int mid = (l + r) / 2;
    return query(2 * idx, lq, rq, l, mid) + query(2 * idx + 1, lq, rq, mid + 1, r);
}

void Solve() {
    int n, q;
    cin >> n >> q;
    nums.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> nums[i];
    segTree.assign(4 * n + 1, 0);
    build(1, 0, n - 1);  // 🟡 index starts at 1

    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int x, y;
            cin >> x >> y;
            update(1, 0, n - 1, x, y);  // 🟡 index starts at 1
        } else {
            int x, y;
            cin >> x >> y;
            cout << query(1, x, y, 0, n - 1) << endl;  // 🟡 index starts at 1
        }
    }
}

int32_t main() {
    int tt_ = 1;
    while (tt_--) {
        Solve();
    }
    return 0;
}
