#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t; cin>>t;
    while(t--){
        ll N, Q, ans = LLONG_MAX;
        cin >> N >> Q;
        string R1, R2;
        cin >> R1 >> R2;

        vector<ll> pos1, pos2;
        for (ll i = 0; i < N; i++) {
            if (R1[i] == '1') pos1.push_back(i + 1);
            if (R2[i] == '1') pos2.push_back(i + 1);
        }

        ll m1 = pos1.size(), m2 = pos2.size();
        vector<ll> pref(m1 + 1, 0), suff(m2 + 1, 0);
        for (ll i = 0; i < m2; i++) {
            ll src = pos2[m2 - 1 - i], target = N - i;
            suff[i + 1] = suff[i] + abs(src - target);
        }
        for (ll i = 0; i < m1; i++) {
            pref[i + 1] = pref[i] + abs(pos1[i] - (i + 1));
        }
        
        for (ll c = 1; c <= N; c++) {
            if (c <= m1 && (N - c + 1) <= m2) {
                ll cost = pref[c] + suff[N - c + 1];
                ans = min(ans, cost);
            }
        }

        if (ans == LLONG_MAX) 
            cout << -1 << "\n";
        else 
            cout << ans << "\n";
    }
    return 0;
}