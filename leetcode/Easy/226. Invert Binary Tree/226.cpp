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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* head = new TreeNode(root->val);
        TreeNode* cur = head;
        build(cur, root);
        return head;
    }

    void build(TreeNode* cur, TreeNode* root){
        if(root == nullptr) return;
        if(root->right != nullptr) cur->left = new TreeNode(root->right->val);
        if(root->left != nullptr) cur->right = new TreeNode(root->left->val);
        build(cur->left, root->right);
        build(cur->right, root->left);
    }
};


// Iteration
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        TreeNode* head = new TreeNode(root->val);
        queue<TreeNode*> q;
        queue<TreeNode*> q_cur;
        q.push(root);
        q_cur.push(head);
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* now = q.front();
                TreeNode* cur_now = q_cur.front();
                q.pop();
                q_cur.pop();
                if(now->left != nullptr){
                    cur_now->right = new TreeNode(now->left->val);
                    q.push(now->left);
                    q_cur.push(cur_now->right);
                }

                if(now->right != nullptr){
                    cur_now->left = new TreeNode(now->right->val);
                    q.push(now->right);
                    q_cur.push(cur_now->left);
                }
            }
        }
        return head;
    }
};

// TC: O(n)
// SC: O(n)
