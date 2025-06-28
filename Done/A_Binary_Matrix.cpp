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
    int n, m; cin>>n>>m;
    vector<string> vs(n);
    for(int i = 0; i<n; i++){
        cin>>vs[i];
    }
    vi Row, Col;
    for(int i = 0; i<n; i++){
        int Xor = 0;
        for(int j =0; j<m; j++){
            Xor^= (vs[i][j]-'0');
        }
        if(Xor==1)
            Row.push_back(i);
    }
    for(int j = 0; j<m; j++){
        int Xor = 0;
        for(int i = 0; i<n; i++){
            Xor^= (vs[i][j]-'0');
        }
        if(Xor==1)
            Col.push_back(j);
    }
    int a = Row.size(), b = Col.size();
    cout<< max(a, b)<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}