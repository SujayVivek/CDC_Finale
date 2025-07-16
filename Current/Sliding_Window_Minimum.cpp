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
    int x, a, b, c; cin>>x>>a>>b>>c;

    int xoR = 0;
    deque<pair<int,int>> dq;
    int curr = x;

    for(int i = 0; i<n; i++){
        while(!dq.empty() && curr<=dq.back().first){
            dq.pop_back();
        }
        dq.emplace_back(curr, i);

        if(!dq.empty() && dq.front().second<= i - k){
            dq.pop_front();
        }

        if(i>=k-1){
            xoR^= dq.front().first;
        }

        curr = (a*curr + b)%c;
    }
    cout<<xoR<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}