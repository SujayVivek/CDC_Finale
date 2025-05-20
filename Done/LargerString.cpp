#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"
string P; 
int dp[6][2];
int n;
int calc(int idx, int lo){
    if(idx==n)return 1;
    if(idx>n) return 0;
    if(dp[idx][lo]!=-1) return dp[idx][lo];

    int loLim = P[idx]-'0';
    int hiLim = 9;
    for(int i = loLim; i<=hiLim; i++){
        
    }
}
void Solve() {
    cin>P;
    n = P.length();
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}