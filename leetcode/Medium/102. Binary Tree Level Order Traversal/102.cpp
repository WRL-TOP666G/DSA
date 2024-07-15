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

// Recursion
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, res, 0);
        return res;
    }
    void dfs(TreeNode* root, vector<vector<int>>& res, int depth){
        if(root == nullptr) return;
        if(depth == res.size()){
            vector<int> v;
            res.push_back(v);
        }
        res[depth].push_back(root->val);
        dfs(root->left, res, depth+1);
        dfs(root->right, res, depth+1);
    }
};

// Iteration
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();
                v.push_back(cur->val);
                if(cur->left != nullptr) q.push(cur->left);
                if(cur->right != nullptr) q.push(cur->right);
            }
            res.push_back(v);
        }
        return res;
    }
};

// TC: O(n)
// SC: O(n)
