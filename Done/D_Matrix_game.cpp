#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int maxA;
vvi V;
vi fact, inv;
int modExp(int x, int e= mod-2){
    int r = 1;
    while(e){
        if(e&1) r = (r*x) %mod;
        x = (x*x) %mod;
        e >>= 1;
    }
    return r;
}

void Solve() {
    for (auto v : V) {
        int a = v[0], b = v[1], k = v[2];
        int N = ((a-1)%mod)*(k%mod)%mod;
        N = (N+1)%mod;
        int num= 1;
        for (int i = 0; i < a; i++) { int term = (N-i+mod)% mod; num =(num*term) % mod;}
        int M = ((((b -1)%mod)*(k%mod))%mod*(num*inv[a]%mod))%mod;
        M = (M+1)% mod;
        cout <<N<<" "<<M<<endl;
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        int a, b, k;
        cin >> a >> b >> k;
        V.push_back({a, b, k});
        maxA = max(maxA, a);
    }
    fact.assign(maxA + 1, 1);
    inv.assign(maxA + 1, 1);
    for (int i = 1; i <= maxA; i++) fact[i] = fact[i - 1] * i % mod;
    inv[maxA] = modExp(fact[maxA]);
    for (int i = maxA; i > 0; i--) inv[i - 1] = inv[i] * i % mod;
    Solve();
    return 0;
}
