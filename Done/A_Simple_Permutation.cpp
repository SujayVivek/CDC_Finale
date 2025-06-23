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
set<int>isPrime;
void seive(){
    primes.assign(1e5+5, 0);
    for(int i = 2; i<1e5 + 1; i++){
        if(primes[i]==0){
            isPrime.insert(i);
            for(int j = 2*i; j<1e5+1; j+=i) primes[j] = 1;
        }
    }
}

void Solve() {
    int n; cin>>n;
    int p = max(1LL, n/3);
    while(!isPrime.count(p)) p++;
    vi a;
    int l = p-1, r = p+1;
    a.push_back(p);
    while(l>0 && r<=n){
        a.push_back(l), a.push_back(r);
        l--;r++;
    }
    while(l>0) a.push_back(l), l--;
    while(r<=n) a.push_back(r), r++;
    for(auto A: a) cout<<A<<" ";
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    seive();
    while (tt_--) {
        Solve();
    }
    return 0;
}