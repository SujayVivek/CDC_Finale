#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long

void Solve(){
    int n;cin>>n;
    vector<int>p(n),q(n),a(n),b(n);
    for(int i=0;i<n;i++)cin>>p[i], a[p[i]]=i;
    for(int i=0;i<n;i++)cin>>q[i], b[q[i]]=i;
    
    vector<vector<int>>pos(n);
    for(int v=0;v<n;v++)pos[min(a[v],b[v])].push_back(v);
    vector<int>pw(1,1);
    while(pw.size()<n)pw.push_back(pw.back()*2%mod);
    
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        for(int v:pos[i]) pq.push(v);
        int M=pq.top(), x = 0;
        if(a[M]<=i)x=max(x,q[i-a[M]]);
        if(b[M]<=i)x=max(x,p[i-b[M]]);
        cout<<(pw[M]+pw[x])%mod<<" ";
    }
    cout<<endl;
}

int32_t main(){
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}