#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
vi primes;
vi minp;
void seive(int n){
    minp.assign(n+1, 0);
    primes.clear();
    for(int i = 2; i<=n; i++){
        if(minp[i]==0){
            minp[i] = i;
            primes.push_back(i);
        }
        for(auto p: primes){
            if(i*p>n) break;
            minp[i*p] = p;
            if(p==minp[i]) break;
        }
    }
}
void Solve() {
    int n; cin>>n;
    vi a(n,0);
    for(int i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    vi cnt(n+1, 0); int cntp = 0;
    seive(n);
    int ans = 0;
    for(auto x: a){
        int p = minp[x];
        if(x==p){
            ans+= cntp-cnt[p];
            cntp++;
            cnt[p]++;
        }else{
            int q= minp[x/p];
            if(x!=p*q)continue;
            ans++;
            if(p==q){
                ans+= cnt[q];
                ans+= cnt[x];
            }else{
                ans+= cnt[p]+cnt[q]+cnt[x];
            }
            cnt[x]++;
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}