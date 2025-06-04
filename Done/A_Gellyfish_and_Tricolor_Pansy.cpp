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
    int a, b, c, d; cin>>a>>b>>c>>d;
    if(c>=d){
        if(d>a && b>a){
            cout<<"Flower"<<endl;
        }else{
            cout<<"Gellyfish"<<endl;
        }
    }else{
        if(c>=b && a>=b){
            cout<<"Gellyfish"<<endl;
        }else{
            cout<<"Flower"<<endl;
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