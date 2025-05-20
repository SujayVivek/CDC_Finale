#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

// dp[pos][mask][r3][r5][r7][r9][lead]
//   pos   = index in S (0…len)
//   mask  = which of {3,5,7,9} have appeared (bit0=3,1=5,2=7,3=9)  [0..15]
//   r3    = current prefix mod 3   [0..2]
//   r5    = current prefix mod 5   [0..4]
//   r7    = current prefix mod 7   [0..6]
//   r9    = current prefix mod 9   [0..8]
//   lead  = still all leading zeros? (1=yes,0=no)
// We only memoize when tight==0, so we omit tight from the array dims.
static int dp[20][16][3][5][7][9][2];
string S;

// Digit‐DP recursion
int dfs(int pos, bool tight, int mask,
        int r3, int r5, int r7, int r9, bool lead) {
    if (pos == (int)S.size()) {
        // must have used at least one odd digit
        if (mask == 0) return 0;
        // for each used digit, ensure final remainder ≠ 0
        if ((mask & 1) && r3 == 0) return 0;  // used 3
        if ((mask & 2) && r5 == 0) return 0;  // used 5
        if ((mask & 4) && r7 == 0) return 0;  // used 7
        if ((mask & 8) && r9 == 0) return 0;  // used 9
        return 1;
    }
    // only memoize when tight==false
    if (!tight && dp[pos][mask][r3][r5][r7][r9][lead] != -1)
        return dp[pos][mask][r3][r5][r7][r9][lead];

    int limit = tight ? (S[pos] - '0') : 9;
    int res = 0;

    // (1) stay in leading zeros by placing '0'
    if (lead) {
        bool nt = tight && (0 == limit);
        res += dfs(pos+1, nt, mask, r3, r5, r7, r9, true);
    }

    // (2) place one of {3,5,7,9}
    static int D[4] = {3,5,7,9};
    for (int d : D) {
        if (d > limit) break;           // if tight, can't exceed
        bool nt = tight && (d == limit);
        int nm = mask;
        if (d == 3) nm |= 1;
        if (d == 5) nm |= 2;
        if (d == 7) nm |= 4;
        if (d == 9) nm |= 8;
        int nr3 = (r3*10 + d) % 3;
        int nr5 = (r5*10 + d) % 5;
        int nr7 = (r7*10 + d) % 7;
        int nr9 = (r9*10 + d) % 9;
        res += dfs(pos+1, nt, nm, nr3, nr5, nr7, nr9, false);
    }

    if (!tight)
        dp[pos][mask][r3][r5][r7][r9][lead] = res;
    return res;
}

// Count special numbers in [1..x]
int countSpecial(long long x) {
    if (x <= 0LL) return 0;
    S = to_string(x);
    memset(dp, -1, sizeof(dp));
    return dfs(0, true, 0, 0, 0, 0, true);
}

void Solve() {
    long long l, r, k;
    cin >> l >> r >> k;

    long long ans = -1;
    long long lo = l, hi = r;
    // binary-search smallest X in [l,r] with
    // countSpecial(X) - countSpecial(l-1) >= k
    while (lo <= hi) {
        long long mid = lo + ((hi - lo) >> 1);
        long long have = countSpecial(mid) - countSpecial(l - 1);
        if (have >= k) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) Solve();
    return 0;
}
