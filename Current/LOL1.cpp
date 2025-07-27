#include<bits/stdc++.h>

#include <vector>
using namespace std;
static const int MOD = 1000000007;
int main() {
    int n; cin>>n;
    vector<int> arr(n);
    for(auto &x: arr) cin>>x;
    // int n = arr.size();
    if (n == 0) return 1;                // only the all-zero final array

    // 1) Find maximum value M in arr
    int M = 0;
    for (int v : arr)
        if (v > M) M = v;

    // 2) Build frequency of each positive value
    vector<int> freq(M+1, 0);
    for (int v : arr)
      if (v > 0)
        freq[v]++;

    // 3) Build the "row‐counts" h[k] = number of elements >= k
    vector<int> h(M+1, 0);
    int running = 0;
    for (int k = M; k >= 1; --k) {
        running += freq[k];
        h[k] = running;
    }

    // 4) Count distinct subsequences of h[1..M]
    //    dp[i] = #distinct subsequences of prefix h[1..i], including the empty one.
    vector<int> dp(M+1, 0);
    dp[0] = 1;
    // last_occ[x] = last index i where h[i] == x
    vector<int> last_occ(n+1, 0);

    for (int i = 1; i <= M; ++i) {
        // doubling the count (include or exclude position i)
        long long twice = (2LL * dp[i-1]) % MOD;
        dp[i] = int(twice);

        int x = h[i];
        if (last_occ[x] != 0) {
            // subtract the overcount of subsequences that would duplicate
            dp[i] = (dp[i] - dp[last_occ[x] - 1] + MOD) % MOD;
        }
        last_occ[x] = i;
    }
    cout<<dp[M]<<endl;
    return 0;
}
