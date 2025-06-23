#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n, k; cin>>n>>k;
    vector<int> a(n, 0);
    int S = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; S += a[i];
        mx = max(mx, a[i]);
    }
    // cout<<mx<<endl;
    int lo = 0, hi = mx + S + k;
    auto check = [&](int Num) {
        int tot = 0;
        for (int i = 0; i < n; i++) {
            int xi = min(a[i], Num), yi = max(0LL, Num -a[i] -k);
            tot += xi + yi ;
            // cout<<"TOT"<<tot<<endl;
            if (tot>=S) break;
        }
        return tot;
    };
    while (lo<hi) {
        int mid = lo+(hi-lo)/2;
        if (check(mid) >= S) hi = mid;
        else lo = mid + 1;
    }
    int num = lo, maxi = check(num), cost = 0;
    for (int i = 0; i < n; i++) {
        int ai = a[i], xi = min(ai, num) ,yi = max(0LL, num - ai - k);

        cost += xi*(xi+1)/2;
        if (yi > 0) {
            cost += yi*(2*ai+yi+1)/2 + yi*k;
            // cost++;
        }
    }
    // cout<<"HI "<<cost<<" "<<maxi<<" "<<S<<endl;
    cout <<cost-(maxi-S)*num << endl;
}

int32_t main() {
    int tt_;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
