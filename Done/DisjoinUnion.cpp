#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vi Rank, par;

int find(int x){
    if(par[x]==x){
       return x;
    }
    else{
        return par[x] = find(par[x]);
    }
}

void merge(int x, int y){
    x = find(x), y = find(y);
    if(Rank[x]>=Rank[y]){
        Rank[x] += Rank[y];
        par[y] = x;
    }else{
        Rank[y]+= Rank[x];
        par[x] = y;
    }
}
void Solve() {
    int n; cin>>n;
    Rank.assign(n+1, 0), par.assign(n+1, 0);
    for(int i = 0; i<n; i++){
        Rank[i]= 1, par[i] = i;
    }
    int q; cin>>q;
    while(q--){
        int com, x, y; cin>>com>>x>>y;
        if(com){
            if(find(x) == find(y)) cout<<1<<endl;
            else cout<<0<<endl;
        }else{
            merge(x, y);
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