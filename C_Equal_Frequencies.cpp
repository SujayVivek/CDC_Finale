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
    int n; string s; cin>>n>>s;
    vi hash_a(26, 0);
    for(int i = 0; i<n; i++) hash_a[s[i]-'a']++;
    vector<pair<int,int>> hash_b(n+1, 0);
    for(int i = 0; i<26; i++) {
        pair<int,int> f = hash_b[hash_a[i]];
        f.first+=1; f.second = hash_a[i];
        hash_b[hash_a[i]] = f;
    }
    sort(hash_b.begin(), hash_b.end(), greater<int>());
    for(int i = 0; i<n; i++){
        if(n%hash_b[i].second) continue;
        int f = hash_b[i].first, s = hash_b[i].second;
        int needed_char = 0;
        int change_tot = 0;
        for(int i = 0; i<26; i++){
            int changes = 0;
            if(hash_a[i]<s && !needed_char){
                needed_char = s-hash_a[i];
            }else if(hash_a[i]>s && !needed_char){
                needed_char = s-(hash_a[i]-s);
            }else if(hash_a[i]<s && needed_char){
                int new_num = max(0, hash_a[i]-needed_char); changes = hash_a[i]-new_num;
                needed_char-=changes;
                hash_a[i] = new_num;
                if(hash_a[i]) needed_char = s-hash_a[i];
            }else if(hash_a[i]>s && needed_char){
                int new_needed = max(0, needed_char - (hash_a[i]-s));
                if(new_needed){
                    needed_char = new_needed;
                }else{
                    needed_char = hash_a[i]-s-needed_char;
                }
                hash_a[i] = s;
                
            }
            change_tot+= changes;
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