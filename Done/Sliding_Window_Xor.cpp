#include <bits/stdc++.h>
using namespace std;
#define int long long

void Solve() {
    int n, k; cin>>n>>k;
    int x, a, b, c; cin>>x>>a>>b>>c;
    int xoR = 0;

    deque<int> dq;
    int curr = x;

    for(int i = 0; i < k; i++){
        dq.push_back(curr);
        xoR ^= curr;
        curr = (a * curr + b) % c;
    }

    int ans = xoR;

    for(int i = k; i < n; i++){

        int outgoing = dq.front(); dq.pop_front();
        dq.push_back(curr);

        xoR ^= outgoing; 
        xoR ^= curr;    

        ans ^= xoR;
        curr = (a * curr + b) % c;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    Solve();
    return 0;
}
