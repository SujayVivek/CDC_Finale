#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ff first
#define ss second
typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
#define int long long
#define endl "\n"

struct TreeNode{
    int val;
    TreeNode* left, right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
TreeNode* insert(TreeNode* root, int val){
    if(!root) return new TreeNode(val);
    if(val<root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}
bool isBst(TreeNode* root, int lo, int hi){
    if(!root) return true;
    if(root->val<lo || root->val>hi) return false;
    return isBst(root->left, lo, root->val) && isBst(root->right, root->val , hi);
}

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL){
        return root;
    }
    if(p->val < root->val && q->val< root->val) return lca(root->left, p, q);   //either both left
    if(p->val > root->val && q->val > root->val) return lac(root->right, p, q); //either both right
    return root; //both left&right or, we are standing on p or q
}

TreeNode* bstFromPreOrder(vi &a){
    int i = 0;
    return build(A, i, INT_MAX);
}
TreeNode* build(vi &a, int i, int bound){
    if(i == a.size() || a[i]>bound) return NULL;
    TreeNode* root = new TreeNode(a[i++]);
    root->left = build(a, i, root->val);
    root->right = build(a, i, bound);
    return root;
}
void inorder_traversal(TreeNode* root){
    if(!root) return;

    inorder_traversal(root->left);
    cout<<root->val<<" ";
    inorder_traversal(root->right);
}
void calc(TreeNode* root, int key){
    if(root == NULL) return root;
    if(root->val == key) return helper(root);

    TreeNode* dummy = root;
    while(root!=NULL){
        if(key<root->val){
            if(root->left!=NULL && root->left->val == key){
                root->left = helper(root->left);
            }else{
                root = root->left;
            }
        }else{
            if(root->right!=NULL && root->right->val == key){
                root->right = helper(root->right);
            }else{
                root = root->right;
            }
        }
    }
}
TreeNode* helper(TreeNode* root){
    if(root->right == NULL) return root->left;
    else if(root->left == NULL) return root->right;

    TreeNode* rightchild = root->rigth;
    TreeNode* rght = FindLastRight(root->left);
    rght->right = rightchild;
    return root->left;
}

TreeNode* FindLastRight(TreeNode* root){
    if(root->right == NULL){
        return root;
    }
    FindLastRight(root->right);
}
void Solve() {

}

int32_t main() {
    int tt_ = 1;
    cin >> tt_;
    while (tt_--) {
        Solve();
    }
    return 0;
}