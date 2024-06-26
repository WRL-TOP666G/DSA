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
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return helper(nums, 0, nums.length-1);
    }

    private TreeNode helper(int[] nums, int l, int r){
        if(l>r) return null;
        int m = (r-l)/2+l;
        TreeNode root = new TreeNode(nums[m]);
        root.left = helper(nums, l, m-1);
        root.right = helper(nums, m+1, r);

        return root;
    }
}

// TC: O(n)
// SC: O(log(n))