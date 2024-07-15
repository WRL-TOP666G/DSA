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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        else if(p == nullptr || q == nullptr) return false;
        if(p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Iteration
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        else if(p == nullptr || q == nullptr) return false;
        queue<TreeNode*> qu;
        qu.push(p);
        qu.push(q);
        while(!qu.empty()){
            TreeNode* nodeP = qu.front();
            qu.pop();
            TreeNode* nodeQ = qu.front();
            qu.pop();

            if(nodeP == nullptr && nodeQ == nullptr) continue;
            if(nodeP == nullptr || nodeQ == nullptr) return false;
            if(nodeP->val != nodeQ->val) return false;
            
            qu.push(nodeP->left);
            qu.push(nodeQ->left);
            qu.push(nodeP->right);
            qu.push(nodeQ->right);
        }

        return true;
    }
};

// TC: O(n)
// SC: O(n)