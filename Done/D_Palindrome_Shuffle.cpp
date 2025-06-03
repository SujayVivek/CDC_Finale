#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

bool check(int mid, string p){
    int n = p.length();
    bool ok = true; vi cnt(26, 0), cnt2(26, 0);
    for(int i = 0; i<n; i++) cnt[p[i]-'a']++;
    for(int i = mid; i<n-mid; i++){
        if(p[i]!=p[n-i-1]){
            ok = false; break;
        }else{
            cnt[p[i]-'a']-=2;
        }
    }
    if(!ok) return ok;
    for(int i = 0; i<mid; i++){
        cnt2[p[i]-'a']++;
    }
    for(int i = 0; i<26; i++){
        if(cnt2[i]<(cnt[i]+1)/2) ok = false;
    }
    return ok;
}

int bs(string p, int unused_i){
    int n = p.length();
    int lo = 0, hi = n;
    int ans = n;
    while(lo<=hi){
        int mid= lo + (hi - lo)/2;
        if(check(mid, p)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }
    return ans;
}

void Solve() {
    string s; cin>>s;
    int n = s.length();
    int i = 0;
    while(i < n-1-i && s[i]==s[n-1-i]) i++;
    if(i >= n-1-i){ cout<<0<<endl; return; }
    string p = s.substr(i, n-2*i);
    string q = p; reverse(q.begin(), q.end());
    cout<< min(bs(p, i), bs(q, i))<<endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
