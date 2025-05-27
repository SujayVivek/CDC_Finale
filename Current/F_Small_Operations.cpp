#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

vector<pair<int,int>> factors(int n){
    vector<pair<int,int>> v;
    for(int i = 2; i*i<=n; i++){
        if(n%i==0){
            int c = 0;
            while(n%i==0){n/=i, c++;}
            v.emplace_back(i, c);
        }
    }
    if(n>1) v.emplace_back(n, 1);
    return v;
}
void number(vector<pair<int,int>> &F, int idx, int cur, vi &res){
    if(idx==F.size()){res.push_back(cur); return;}
    auto p = F[idx]; int a = p.first, b = p.second;
    for(int j = 0; j<=b; j++){
        number(F, idx + 1, cur, res);
        cur*=a;
    }
}
int calc(int n, int k){
    if(n==1) return 0;
    vector<pair<int,int>> F = factors(n);
    vi num; number(F, 0, 1, num);
    sort(num.begin(), num.end());
    map<int,int> mpp;
    for(int i = 0; i<num.size(); i++) mpp[num[i]] = i;
    vi s;
    for(auto x: num) if(x>1 && x<=k )s.push_back(x);
    vi dist(num.size(), -1);
    queue<int> q; dist[0] = 0; q.push(0);
    while(!q.empty()){
        int i = q.front(); q.pop();
        int u = num[i];
        for(auto ch : s){
            int w = u*ch;
            if(w>n || n%w) continue;
            int j = mpp[w];
            if(dist[j]==-1){
                dist[j] = dist[i] + 1;
                if(w==n) return dist[j];
                q.push(j);
            }
        }
    }
    return -1;
}
void Solve() {
    int x, y, k; cin>>x>>y>>k;
    if(x==y){cout<<0<<endl; return;}
    if(k==1){cout<<-1<<endl; return;}
    int g = __gcd(x, y);
    int a = y/g, b = x/g;
    int u = calc(a, k);
    if(u==-1){cout<<-1<<endl; return;}
    int v = calc(b, k);
    if(v==-1){cout<<-1<<endl; return;}
    cout<< u + v<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}