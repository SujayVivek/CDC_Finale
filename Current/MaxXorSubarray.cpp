#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

struct Node {
    Node* child[2];
    Node() {
        child[0] = child[1] = nullptr;
    }
};

class BinaryTrie {
private:
    Node* root;
    const int MAXB = 30; 

public:
    BinaryTrie() {
        root = new Node();
    }

    void insert(int x) {
        Node* node = root;
        for (int i = MAXB; i >= 0; --i) {
            int bit = (x >> i) & 1;
            if (!node->child[bit]) {
                node->child[bit] = new Node();
            }
            node = node->child[bit];
        }
    }

    int getMaxXOR(int x) {
        Node* node = root;
        int res = 0;
        for (int i = MAXB; i >= 0; --i) {
            int bit = (x >> i) & 1;
            int want = bit ^ 1;
            if (node->child[want]) {
                res |= (1LL << i);
                node = node->child[want];
            } else if (node->child[bit]) {
                node = node->child[bit];
            } else {
                break;
            }
        }
        return res;
    }
};

void Solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    BinaryTrie trie;
    trie.insert(0);  // Prefix XOR before any element is 0

    int prefix_xor = 0;
    int max_xor = 0;

    for (int i = 0; i < n; ++i) {
        prefix_xor ^= a[i];
        max_xor = max(max_xor, trie.getMaxXOR(prefix_xor));
        trie.insert(prefix_xor);
    }

    cout << max_xor << endl;
}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}
