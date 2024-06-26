/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    vector<TreeNode*> v;
    TreeNode* balanceBST(TreeNode* root) {
        in_order_traversal(root);
        TreeNode *res = rebuild(0, v.size()-1); 
        return res;
    }
    void in_order_traversal(TreeNode* root){
        if(root == NULL) return;
        in_order_traversal(root->left);
        v.push_back(root);
        in_order_traversal(root->right);
    }

    TreeNode* rebuild(int l, int r){
        if(l>r) return NULL;
        int m = (r-l)/2+l;
        TreeNode* root = v[m];
        root->left = rebuild(l, m-1);
        root->right = rebuild(m+1, r);
        return root;
    }
};

// TC: O(n)
// SC: O(n)
