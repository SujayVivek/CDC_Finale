#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

const int MOD = 998244353;
int modpow(int a, int e = MOD-2) {
    int r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int32_t main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int N = A + B + C + D;
    vi fact(N+1, 1), invf(N+1, 1);
    for(int i = 1; i <= N; i++){
        fact[i] = fact[i-1] * i % MOD;
    }
    invf[N] = modpow(fact[N]);
    for(int i = N; i >= 1; i--){
        invf[i-1] = invf[i] * i % MOD;
    }
    auto choose = [&](int n, int r){
        if (r < 0 || r > n) return 0LL;
        return fact[n] * invf[r] % MOD * invf[n-r] % MOD;
    };
    int ans = 0;
    for(int k = 0; k <= B; k++){
        int waysAB = choose(A + B - k - 1, A - 1);
        int waysBG = choose(C + D + k, C);
        ans = (ans + waysAB * waysBG) % MOD;
    }
    cout << ans << "\n";
    return 0;
}