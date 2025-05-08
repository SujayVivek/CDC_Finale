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
    string s; int n;
    cin>>n>>s;
    s="0"+s;
    int ans = 0, cur = s[0];
    for (int i = 1; i <= n; i++) {
        int dig = s[i];
        if (cur != dig) 
           ans++;
        cur = dig;
    }
   if(ans>=3)
     cout<< ans-2 + n<<endl;
   else if(ans==2)
     cout<< ans-1 + n<<endl;
   else 
     cout<<ans+n<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}