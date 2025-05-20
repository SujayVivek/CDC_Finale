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
    vvi v(k, vi(n, 0));
    for(int i = 0; i<k; i++){
        for(int j = 0; j<n; j++) cin>>v[i][j];
    }
    if(k<2) {cout<<"YES"<<endl; return;}
    vi a = v[0], b = v[1];
    int left = -1, right = -1;
    if(a[1]==2 && a[1]==1 && k>2) b = v[2];
    for(int i = 1; i<n; i++){
        if(b[i]==1){
            if(i>1) left = b[i-1];
            if(i+1<n) right = b[i+1];
        }
    }
    vi ans;  bool ok = true;
    for(int i = 1; i<n; i++){
        if(i<n && a[i]==right && ok) {ok = false;ans.push_back(1);}
        else if(i>0 && a[i-1]==left && ok) {ok = false;ans.push_back(1);}
        if(i)ans.push_back(a[i]);
    } 
    for(int i = 0; i<k; i++){
        vi cmp = v[i]; int l = 0;
        // if(cmp[0]!=i+1){cout<<"NO"<<endl; return;}
        for(auto it: ans)cout<<it<< " ";
        cout<<endl;
        for(int j = 1; j<n && l<n; j++){
            if(ans[l]==cmp[0]) {l++; j--;continue;}
            if(ans[l]!=cmp[j]){cout<<"NO "<<i<<" "<<j<<" "<<l<<endl; return;}
            l++;
        }
    }
    cout<<"YES"<<endl; return;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}