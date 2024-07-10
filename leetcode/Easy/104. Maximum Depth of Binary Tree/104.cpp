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
    int max_depth = 0;
    int maxDepth(TreeNode* root) {
        helper(root, 1);
        return max_depth;
    }
    void helper(TreeNode* root, int depth){
        if(root == nullptr) return;
        max_depth = max(max_depth, depth);
        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }
};

// Iteration
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        int depth = 0;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* now = q.front();
                q.pop();
                if(now->left != nullptr) q.push(now->left);
                if(now->right != nullptr) q.push(now->right);
            }   
            depth++;
        }
        return depth;
    }
};

// TC: O(n)
// SC: O(n)
