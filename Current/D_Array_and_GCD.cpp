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
void generate_primes(int limit) {
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= limit; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
}

void Solve() {
    int n; cin>>n;
    vi a(n,0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int j = 0; int coins = 0;int i = 0;
    for( i = 0; i<n; i++){
        if(a[i]>primes[j]){
            coins += a[i]-primes[j];
            j++;
        }else{
            if(coins>=(primes[j]-a[i])){
                coins-=(primes[j]-a[i]);
                j++;
            }else{
                break;
            }
        }
    }
    cout<< n-1-i+1<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    generate_primes(7e6);
    while (tt_--) {
        Solve();
    }
    return 0;
}