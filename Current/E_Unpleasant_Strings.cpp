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
    int n, k; cin>>n>>k;
    vvi char_pos(k);
    string s; cin>>s;
    for(int i = 0; i<n; i++){
        char_pos[s[i]-'a'].push_back(i);
    }
    int q; cin>>q;
    while(q--){
        int cur_idx = 0;
        string S; cin>>S;
        bool ok = true;
        for(int i = 0; i<S.length(); i++){
            int dist = lower_bound(char_pos[S[i]-'a'].begin(), char_pos[S[i]-'a'].end(), cur_idx+1) - char_pos[S[i]-'a'].begin();
            // cout<<i+1<<" "<<dist<<" "<<cur_idx<<endl;

            if(dist>=char_pos[S[i]-'a'].size()){
                ok = false;
                // cout<<"HI"<<endl;
                cout<<0<<endl; break;
            }
            cur_idx = char_pos[S[i]-'a'][dist];
            // cout<<"cur idx = "<<cur_idx<<endl;
        }
        if(ok){
            int mn = 1e18;
            for(int i = 0; i<k; i++){
                int dist = distance(lower_bound(char_pos[i].begin(), char_pos[i].end(), cur_idx+1), char_pos[i].end());
                cout<<dist<<" = dist"<<endl;
                mn = min(mn, dist+1);
            }
            cout<<mn<<endl;
        }
    }

}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}