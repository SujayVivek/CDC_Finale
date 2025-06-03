#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

void Solve(){
    int n,m;cin>>n>>m;
    vi a(m,0);
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    vector<pair<int,int>>v;
    for(int i=0;i<m;i++){
        v.push_back({a[i]/100,a[i]});
    }
    sort(v.begin(),v.end());
    vi fl; vvi rm;
    for(int i=0;i<m;i+=0){
        int j=i,f=v[i].ff;
        fl.push_back(f);
        rm.push_back(vi());
        while(j<m&&v[j].ff==f){
            rm.back().push_back(v[j].ss);
            j++;
        }
        sort(rm.back().begin(),rm.back().end());
        i=j;
    }
    int sz=fl.size();
    vi lc(sz), rc(sz);
    for(int i=0;i<sz;i++){
        lc[i]=rc[i]=rm[i].size();
    }
    vi fu(sz,0), su(sz,0);
    vi fa(n), sa(n);
    int l1=0, l2=sz-1;
    int r1=0, r2=sz-1;
    for(int i=0;i<n;i++){
        int af,bf;
        if(i>=n/2){
            while(l2>=l1&&lc[l2]==0) l2--;
            af=l2; lc[af]--;
            while(r1<=r2&&rc[r1]==0) r1++;
            bf=r1; rc[bf]--;
        }else{
            while(l1<=l2&&lc[l1]==0) l1++;
            af=l1; lc[af]--;
            while(r2>=r1&&rc[r2]==0) r2--;
            bf=r2; rc[bf]--;
        }
        fa[i]=af, sa[i]=bf, fu[af]++, su[bf]++;
    }
    vvi ra(sz),rb(sz);
    for(int i=0;i<sz;i++){
        for(int j = 0; j< su[i]; j++){
            rb[i].push_back(rm[i][j]);
        }
        for(int j = 0; j< fu[i]; j++){
            ra[i].push_back(rm[i][j]);
        }
    }
    vi pa(sz,0),pb(sz,0);
    for(int i=0; i<n ;i++){
        int af= fa[i];
        int bf= sa[i];
        int x= ra[af][pa[af]++];
        int y= rb[bf][pb[bf]++];
        cout<<x<<" "<<y<<" "<<x<<" "<<y<<" "<<x<<" "<<y<<endl;
    }
}

int32_t main(){
    int tt_=1;
    cin>>tt_;
    while(tt_--){
        Solve();
    }
    return 0;
}