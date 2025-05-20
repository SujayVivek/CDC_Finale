#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const int MAXL = 50;         // max number of digits we support
const int MAXS = MAXL * 9;   // max digit‐sum = 450
const int MAXP = 2 * MAXS;   // we need primes up to 900
const int64 MOD = 1000000007;

string s;
int n;
bool is_prime[MAXP+1];
int64 memo[MAXL+2][2][2][2][MAXS+1][MAXS+1];
bool seen[MAXL+2][2][2][2][MAXS+1][MAXS+1];

int64 dp(int idx, int tight1, int tight2, int cmp, int sum1, int sum2) {
    if (idx == n) {
        if (cmp == 1 && sum1 < sum2 && is_prime[sum1 + sum2])
            return 1;
        return 0;
    }
    if (seen[idx][tight1][tight2][cmp][sum1][sum2])
        return memo[idx][tight1][tight2][cmp][sum1][sum2];
    seen[idx][tight1][tight2][cmp][sum1][sum2] = true;
    
    int64 res = 0;
    int lim1 = tight1 ? (s[idx] - '0') : 9;
    int lim2 = tight2 ? (s[idx] - '0') : 9;

    for (int d1 = 0; d1 <= lim1; ++d1) {
        for (int d2 = 0; d2 <= lim2; ++d2) {
            int ncmp = cmp;
            if (cmp == 0) {
                if (d1 < d2)       ncmp = 1;
                else if (d1 > d2)  continue; 
            }
            int nt1 = tight1 && (d1 == lim1);
            int nt2 = tight2 && (d2 == lim2);
            res = (res + dp(idx+1, nt1, nt2, ncmp, sum1 + d1, sum2 + d2)) % MOD;
        }
    }

    memo[idx][tight1][tight2][cmp][sum1][sum2] = res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Read input
    cin >> s;
    n = s.length();
    if (n > MAXL) {
        // too big for this recursive version
        // (you’d need the single‐number DP approach for >50 digits)
        return 0;
    }

    // 2) Sieve primes up to 2 * (9*n)
    int P = 2 * 9 * n;
    fill(is_prime, is_prime + P + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= P; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= P; j += i)
                is_prime[j] = false;
        }
    }

    // 3) Clear memoization flags
    memset(seen, 0, sizeof(seen));

    // 4) Run recursion
    cout << dp(0, 1, 1, 0, 0, 0) << "\n";
    return 0;
}
