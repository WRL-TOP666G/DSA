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

// Recursive
class Solution {
public:
    int sum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        helper(root);
        return root;
    }

    void helper(TreeNode* root){
        if(root==NULL) return;
        helper(root->right);
        sum += root->val;
        root->val = sum;
        helper(root->left);
    }
};

// TC: O(n)
// SC: O(log(n))

// Iteration
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(!s.empty() || cur!=nullptr){
            while(cur!=nullptr){
                s.push(cur);
                cur = cur->right;
            }

            cur = s.top();
            s.pop();
            sum += cur->val;
            cur->val = sum;
            cur = cur->left;
        }
        return root;
    }
};

// TC: O(n)
// SC: O(log(n))
