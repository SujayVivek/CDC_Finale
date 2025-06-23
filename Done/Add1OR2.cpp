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
    int n; cin>>n;
    vi a(n,0), b(n, 0);
    int Sbi = 0, mx = 0;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<n; i++){
        cin>>b[i];
        // a[i]+= b[i];
        Sbi+= b[i];
        mx = max(mx, a[i]);
    }
    int cnt2 = Sbi*2;
    int lo = mx, hi = mx + cnt2;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo)/2;
        __int128 usage = 0, Sum = 0;
        vector<int> V;
        for(int i = 0; i<n; i++){
            int p = min(mid - a[i], b[i]);
            int new_bi = b[i] - p;
            usage += new_bi;
            Sum+= mid - a[i];
            V.push_back(a[i]+p);
        }
        bool ok = true;
        for(int i = 0; i<n; i++){
            usage-= (mid - V[i])/2;
        }
        if(usage>0){
            lo = mid + 1;
        }else{
            hi = mid - 1;
            ans = mid;
        }
        // cout<<mid<<" hi "<<usage<<" sum = "<<Sum<<endl;
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}