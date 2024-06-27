/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

// Recursive
class Solution {
    int sum = 0;
    public TreeNode bstToGst(TreeNode root) {
        traversal(root);
        return root;
    }

    private void traversal(TreeNode root){
        if(root==null) return;
        traversal(root.right);
        sum += root.val;
        root.val = sum;
        traversal(root.left);
    }
}

// TC: O(n)
// SC: O(log(n))


// Iteration
class Solution {
    public TreeNode bstToGst(TreeNode root) {
        int sum = 0;
        Stack<TreeNode> stack = new Stack<>();
        TreeNode cur = root;
        while(!stack.isEmpty() || cur != null){
            while(cur!=null){
                stack.push(cur);
                cur = cur.right;
            }
            cur = stack.pop();
            sum += cur.val;
            cur.val = sum;
            cur = cur.left;
        }

        return root;
    }
}

// TC: O(n)
// SC: O(log(n))
