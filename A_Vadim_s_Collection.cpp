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
    vi freq(10, 0);
    for(int i = 0; i<s.length(); i++){
        freq[s[i]-'0']++;
    }
    int i = 0;
    for(int i = 9; i>=0; i--){
        if(freq[i]){
            cout<<i; freq[i]--;
        }else{
            int j = i+1;
            while(j<=9 && !freq[j]) j++;
            cout<<j; freq[j]--;
        }
    }
    cout<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}