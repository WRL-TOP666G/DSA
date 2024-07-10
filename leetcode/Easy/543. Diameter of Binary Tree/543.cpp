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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }

    int helper(TreeNode* root, int& res){
        if(root == nullptr) return 0;
        int L = helper(root->left, res);
        int R = helper(root->right, res);
        res = max(res, L+R);
        return max(L, R) + 1;
    }
};


// TC: O(n)
// SC: O(n)
