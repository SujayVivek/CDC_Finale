#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve() {
    int n; cin>>n;
    string s; cin>>s;
    string p = s; reverse(p.begin(), p.end());
    string s1 = s + '#' + p;
    string s2 = p + '#' + s;
    int mx = 0;
    vi lps1(2*n + 2, 0), lps2(2*n+2, 0);
    int i = 0, j = -1;
    lps1[0] = lps2[0] = -1;
    while(i<2*n+1){
        while(j!=-1 && s1[i]!=s1[j]) j = lps1[j];
        i++, j++; lps1[i] = j;
    }
    mx = max(mx, lps1[2*n+1]);
    i = 0, j = -1;
    while(i<2*n+1){
        while(j!=-1 && s2[i]!=s2[j]) j = lps2[j];
        i++, j++; lps2[i] = j;
    }
    mx = max(mx, lps2[2*n + 1]);
    cout<<mx<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}