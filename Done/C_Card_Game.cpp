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
    if(n==2){
        if(s=="AB"){
            cout<<"Alice"<<endl; return;
        }else if(s=="BA"){
            cout<<"Bob"<<endl; return;
        }
    }
    int B = 0;
    for(int i = 0; i<n; i++){
        if(s[i]=='B') B++;
    }
    if(s[0]=='A' && s[n-1]=='A'){
        cout<<"Alice"<<endl; return;
    }
    if(s[0]=='B' && s[n-1]=='B'){
        cout<<"Bob"<<endl; return;
    }
    if(s[0]=='B' && s[n-1]=='A'){
        if(s[n-2]=='A'){
            cout<<"Alice"<<endl; return;
        }else{
            cout<<"Bob"<<endl; return;
        }
    }
    if(s[0]=='A' && s[n-1]=='B'){
        if(B==1){
            cout<<"Alice"<<endl; return;
        }else{
            cout<<"Bob"<<endl; return;
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