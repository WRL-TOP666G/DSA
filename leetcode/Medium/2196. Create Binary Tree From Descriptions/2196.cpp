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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> isRoot;
        unordered_set<int> notRoots;
        for(const auto& de:descriptions){
            TreeNode* parent = (mp.count(de[0])>0) ? mp[de[0]] : new TreeNode(de[0]);
            TreeNode* child = (mp.count(de[1])>0) ? mp[de[1]] : new TreeNode(de[1]);
            if(de[2] == 1){ // left
                parent->left = child;
            } else { // right
                parent->right = child;
            }
            mp[de[0]] = parent;
            mp[de[1]] = child;

            if(isRoot.empty() || (!notRoots.empty() && !notRoots.contains(de[0]))){
                isRoot.insert(de[0]);
            }
            if(isRoot.contains(de[1])){
                isRoot.erase(de[1]);
            }
            notRoots.insert(de[1]);
        }

        int root = 0;
        for(const auto& r:isRoot){
            cout << r << endl;
            root = r;
        }
        return mp[root];
    }
};

// TC: O(n)
// SC: O(n)
