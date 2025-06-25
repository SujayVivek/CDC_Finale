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
    string s; cin>>s;
    int n = s.length();
    int NG = 0, Y = 0, V = 0, C = 0; int N = 0, G = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='N'){
            N++;
        }else if(s[i]=='G'){
            G++;
        }else if(s[i]=='Y'){
            Y++;
        }else if(s[i]=='A' || s[i]=='E' || s[i]=='O' || s[i]=='I' || s[i]=='U'){
            V++;
        }else{
            C++;
        }
    }
    NG = min(N, G);
    N-=NG, G-=NG; C+=N+G;
    // cout<<NG<<" "<<C<<" "<<V<<endl;
    int mx = 0;
    for(int i = 0; i<=Y; i++){
        int c = Y-i+C, v = i+V;
        for(int j = 0; j<=NG; j++){
            int ng = j, n_g = NG - j;
            int newC = c + 2*n_g;
            int minP = min(ng/2, v);
            int ans= 5*minP;
            int newV = v;
            newV-=minP; ng-=2*minP;
            if(newV>0 && ng>0 && newC>0){
                ans+= 4;
                ng = 0;
                newC--; newV--;
            }
            minP = min(newV, newC/2);
            ans+= 3*minP;
            mx = max(mx, ans);
        }

    }
    cout<<mx<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}