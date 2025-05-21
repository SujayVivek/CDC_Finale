#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

struct Node{
    Node* child[2];
    int cnt;
    Node(){
        for(int i = 0; i<2; i++) child[i] = nullptr;
        cnt = 0;
    }
};

class BinaryTrie{
private: 
    Node* root;  //this is like a variable for this class only. It stores the location of the root node of our trie
    const int MAXB = 30; //max bits

public:
    BinaryTrie(){
        root = new Node(); //a cobnstructor called to initialize root. We create multiple nodes in the future equal to the root node by -> Node* node = root;
    }

    void insert_val(int x){
        Node* node = root;
        for(int i = MAXB; i>=0; i--){
            int bit = (x>>i)&1;
            if(!node->child[bit]) node->child[bit] = new Node();
            node = node->child[bit];
            node->cnt++;
        }
    }

    void erase_val(int x){
        Node* node = root;
        for(int i = MAXB; i>=0; i--){
            int bit = (x>>i)&1;
            Node* nxt = node->child[bit];
            nxt->cnt--;
            node = nxt;
        }
    }

    int get_xor(int x){
        int res = 0;
        Node* node = root;
        for(int i = MAXB; i>=0; i--){
            int bit = (x>>i)&1;
            int want = 1^bit;
            if(node->child[want] && node->child[want]->cnt>0){
                res|= (1<<i); //we want a 1 there, thats why we are just doing OR!
                node= node->child[want];
            }else if(node->child[bit] && node->child[bit]->cnt>0){
                //we get a default 0 at that bit position here. 
                node= node->child[bit];
            }else{
                break;
            }
        }
        return res;
    }
};

void Solve() {
    int q; cin>>q;
    BinaryTrie trie;
    trie.insert_val(0); 
    while(q--){
        int x; char c; cin>>c>>x;
        if(c=='+'){
            trie.insert_val(x);
        }else if(c=='-'){
            trie.erase_val(x);
        }else{
            cout<<trie.get_xor(x)<<endl;
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