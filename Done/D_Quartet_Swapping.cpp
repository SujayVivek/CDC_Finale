#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int calc(vector<int> a) {
    int n = a.size();
    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int>mpp;
    for(int i = 0; i<n; i++)mpp[sorted[i]] = i;
    vector<int> g(n);
    for(int i = 0; i<n; i++)g[i] = mpp[a[i]];
    vector<bool> vis(n, false);
    int swaps = 0;
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            int cycle_len = 0, j = i;
            while(!vis[j]) {
                vis[j] = true;
                j = g[j];
                cycle_len++;
            }
            swaps+= (cycle_len - 1);
        }
    }
    return swaps%2;
}

void Solve() {
    int n; cin >> n;
    vector<int> a(n), ans;
    for(auto &x : a) cin >> x;
    vector<int> odd,eve;
    for(int i = 0; i< n; i++) {
        if(i % 2 == 0) odd.push_back(a[i]);
        else eve.push_back(a[i]);
    }
    vector<int> o =odd, e =eve;
    sort(o.begin(),o.end());
    sort(e.begin(),e.end());
    int swap1 =calc(odd), swap2 =calc(eve); 
    if((swap1 +swap2) % 2 == 0) {
        int i = 0, j = 0;
        while(i <o.size() || j <e.size()) {
            if(i <o.size()) ans.push_back(o[i++]);
            if(j <e.size()) ans.push_back(e[j++]);
        }
    } else {
        vector<int> new_odd =o, new_eve =e;
        if(new_odd.size() >= 2) swap(new_odd[new_odd.size()-1], new_odd[new_odd.size()-2]);
        if(new_eve.size() >= 2) swap(new_eve[new_eve.size()-1], new_eve[new_eve.size()-2]);
        // cout<<"NEW Odd HI"<<endl;
        // for(auto &x: new_odd) cout<<x<<" ";
        
        vector<int> ans1, ans2;
        int i = 0, j = 0;
        // cout<<"NEW eve HI"
        // for(auto &x: new_eve) cout<<x<<" ";
        while(i < new_odd.size() || j < e.size()) {
            if(i < new_odd.size()) ans1.push_back(new_odd[i++]);
            if(j < e.size()) ans1.push_back(e[j++]);
        }
        i = 0, j = 0;
        while(i < o.size() || j < new_eve.size()) {
            if(i < o.size()) ans2.push_back(o[i++]);
            if(j < new_eve.size()) ans2.push_back(new_eve[j++]);
        }
        // for(auto &x: ans1)cout<<x<<" ";

        // for(auto &x: ans2)cout<<" hi="<<x<<endl;
        ans = (ans1 < ans2) ? ans1 : ans2;
    }
    for(auto x : ans) cout << x << " ";
    cout << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}