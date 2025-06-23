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
    vector<string> v(2);
    for(auto &x: v) cin>>x;
    bool mul = false;
    for(int i = 0; i<n; i++){
        if(v[0][i]=='.' && v[1][i]=='.'){
            if(i<n-1 && v[0][i+1]=='.' && v[1][i+1]=='.'){
                mul = true;
                v[0][i] = v[1][i]= v[0][i+1] = v[1][i+1] = '#';
                i++;
            }else{
                v[0][i] = v[1][i] = '#';
            }
        }else if(i<n-1 && v[0][i]=='.' && v[0][i+1] == '.'){
            v[0][i] = v[0][i+1] = '#';
        }else if(i<n-1 && v[1][i]=='.' && v[1][i+1] == '.'){
            v[1][i] = v[1][i+1] = '#';
        }
    }bool ok = true;
    for(int i = 0; i<n; i++){
        ok &= (v[0][i]=='#' && v[1][i]=='#');
    }
    if(!ok) cout<<"None"<<endl;
    else if(ok && !mul) cout<<"Unique"<<endl;
    else cout<<"Multiple"<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}