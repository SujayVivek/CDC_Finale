#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

int n; string s;
int check(int len){
    len/=2;
    vi hash(n,0);
    for(int i = 0; i+len<n; i++){
        if(s[i]==s[i+len]) hash[i] = 1
        if(!i)hash[i]+=hash[i-1];
    }
    for(int i = 0; i+len<n; i++){
        int Sum = hash[i+len]-
    }
}
void Solve() {
    cin>>s;
    n = s.length();
    int lo = 0, hi = s.length();
    while(lo<=hi){
        int mid = (hi - lo)/2 + lo;
        if(check(mid)){

        }
    }
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}