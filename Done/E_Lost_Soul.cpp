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
    map<int, vector<pair<int,int>>>mvp;
    vector<vector<int>> v(2, vector<int>(n, 0));
    for(int i = 0; i<2; i++){
        for(int j = 0; j<n; j++){
            cin>>v[i][j];
            mvp[v[i][j]].push_back({j, (i+j)%2});
        }
    }
    int mn = 0;
    for(int i = 0; i<n; i++){
        if(v[1][i] == v[0][i]) mn = max(mn, i)+1;
    }
    for(auto it: mvp){
        vector<pair<int,int>> V = it.second;
        if(V.size()==1) continue;
        sort(V.begin(), V.end(), greater<pair<int,int>>());
        int N = V.size();
        map<int, set<int>> parity_map;
        for(int i = 0; i<N; i++){
            if(!parity_map[1-V[i].second].empty()){
                mn = max(mn, V[i].first+1); break;
            }else{
                bool ok = false;
                for(auto s: parity_map[V[i].second]){
                    if(s-V[i].first>1){
                        mn = max(mn, V[i].first+1);
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
                parity_map[V[i].second].insert(V[i].first);
            }
        }
    }
    cout<<mn<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}