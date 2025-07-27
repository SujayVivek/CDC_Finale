#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)9e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, days;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    cin >> days;

    // dp_prev[i] = best answer using first i lectures in (d-1) days
    // dp[i]      = best answer using first i lectures in d days
    vector<ll> dp(n+1, INF), dp_prev(n+1, INF);
    dp_prev[0] = 0;

    for(int d = 1; d <= days; d++){
        fill(dp.begin(), dp.end(), INF);
        // To have d days and i lectures, we need i >= d (at least one lecture per day)
        for(int i = d; i <= n; i++){
            int mx = 0;
            // try ending the d-th day with lectures j+1..i
            // j must be >= d-1 (so that the first j lectures fill d-1 days)
            for(int j = i-1; j >= d-1; j--){
                mx = max(mx, a[j]);
                dp[i] = min(dp[i], dp_prev[j] + mx);
            }
        }
        dp_prev.swap(dp);
    }

    cout << dp_prev[n] << "\n";
    return 0;
}