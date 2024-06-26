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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }

    void helper(TreeNode* root, vector<int> &v){
        if(root == NULL) return;
        helper(root->left, v);
        v.push_back(root->val);
        helper(root->right, v);
    }
};

// Iteration
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while(!s.empty() || root!=NULL){
            while(root!=NULL){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            res.push_back(s.top()->val);
            s.pop();
            root = root->right;
        }
        return res;
    }
};

// TC: O(n)
// SC: O(n)
