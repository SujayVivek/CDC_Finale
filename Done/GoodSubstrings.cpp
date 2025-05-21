#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

struct TrieNode{
    array<int, 26> next;
    TrieNode(){
        next.fill(-1);
    }
};
void Solve() {
    string S; cin>>S;
    string bin; cin>>bin;
    int n = S.length();
    int k; cin>>k;
    vi good(26, 0);
    for(int i = 0; i<26; i++) good[i] = (bin[i]=='1');

    vector<TrieNode> trie;
    trie.reserve(n*(n+1)/2);
    trie.emplace_back(); //create the root
    int ans = 0;
    for(int i = 0; i<n; i++){
        int node = 0;
        int bad = 0;
        for(int j = i; j<n; j++){
            int c = S[j]-'a';
            if(!good[c]) bad++;
            if(bad>k) break;

            if(trie[node].next[c]==-1){
                ans++;
                trie[node].next[c] = trie.size();
                trie.emplace_back();
            }
            node = trie[node].next[c];
        }
    }
    cout<<ans<<endl;
}

int32_t main() {
    int tt_ = 1;
    // cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}