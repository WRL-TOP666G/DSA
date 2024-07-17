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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> st;
        for(auto &i:to_delete) st.insert(i);
        helper(root, root, st, true, res, ' ');
        return res;
    }

    void helper(TreeNode* parent, TreeNode* root, unordered_set<int>& st, bool deleted, vector<TreeNode*>& res, char direction){
        if(root == nullptr) return;
        int now = root->val;
        if(!st.contains(now) && deleted){
            res.push_back(root);
        }
        if(st.contains(now)){
            // Remove
            if(direction == ' ') {
                helper(root->left, root->left, st, true, res, ' ');
                helper(root->right, root->right, st, true, res, ' ');
                return;
            }
            else if(direction == 'L') parent->left = nullptr;
            else if(direction == 'R') parent->right = nullptr;
            st.erase(now);
            helper(root, root->left, st, true, res, 'L');
            helper(root, root->right, st, true, res, 'R');
        } else {
            helper(root, root->left, st, false, res, 'L');
            helper(root, root->right, st, false, res, 'R');
        }
    }
};

// Iteration
class Solution {
    // parent, now, sign(L,R, ' '), isDelete
    using nodeData = std::tuple<TreeNode*, TreeNode*, char, bool>;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        unordered_set<int> st;
        for(auto &i:to_delete) st.insert(i);

        queue<nodeData> q;
        if(root != nullptr){
            q.push({root, root, ' ', true});
        }
        while(!q.empty()){
            nodeData curNode = q.front();
            q.pop();
            TreeNode* parent = std::get<0>(curNode);
            TreeNode* cur = std::get<1>(curNode);
            char sign = std::get<2>(curNode);
            bool isDeleted = std::get<3>(curNode);

            if(st.contains(cur->val) && sign == ' '){
                if(cur->left != nullptr) q.push({cur->left, cur->left, ' ', true});
                if(cur->right != nullptr) q.push({cur->right, cur->right, ' ', true});
                continue;
            } 
            if(st.contains(cur->val)){
                if(sign == 'L') parent->left = nullptr;
                else if(sign == 'R') parent->right = nullptr;
                if(cur->left != nullptr) q.push({cur, cur->left, 'L', true});
                if(cur->right != nullptr) q.push({cur, cur->right, 'R', true});
            } else { // not in to_delete 
                if(isDeleted) res.push_back(cur);
                if(cur->left != nullptr) q.push({cur, cur->left, 'L', false});
                if(cur->right != nullptr) q.push({cur, cur->right, 'R', false});
            }
        }
        return res;
    }
};

// TC: O(n)
// SC: O(n)