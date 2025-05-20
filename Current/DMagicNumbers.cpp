#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;
static const int MAXN = 2000;
static const int MAXM = 2000;

int dp[MAXN+1][2][2][MAXM];

string A, B;
int n, m, D;

int calc(int idx, int lo, int hi, int rem) {
    if (idx == n) {
        return rem == 0 ? 1 : 0;
    }
    int &ans = dp[idx][lo][hi][rem];
    if (ans != -1) return ans;

    ans = 0;
    int loLim = lo ? (A[idx] - '0') : 0;
    int hiLim = hi ? (B[idx] - '0') : 9;

    bool wantD = ((idx+1) % 2 == 0);  

    for (int i = loLim; i <= hiLim; ++i) {
        if (wantD) {
            if (i != D) continue;
        } else {
            if (i == D) continue;
        }
        int nL = lo && (i == loLim);
        int nH = hi && (i == hiLim);
        int nR = (rem * 10 + i) % m;
        ans = ans + calc(idx+1, nL, nH, nR);
        if (ans >= MOD) ans -= MOD;
    }
    return dp[idx][lo][hi][rem] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> m >> D;
        cin >> A >> B;
        n = A.size();
        memset(dp, -1, sizeof(dp));
        int result = calc(0, 1, 1, 0);
        cout << result << "\n";
    }
    return 0;
}
