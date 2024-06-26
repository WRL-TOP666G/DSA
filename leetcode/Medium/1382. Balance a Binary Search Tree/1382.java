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
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        in_order_traversal(root, list);
        TreeNode res = rebuild(list, 0, list.size()-1);
        return res;
    }

    private void in_order_traversal(TreeNode root, List<Integer> list){
        if(root == null) return;
        in_order_traversal(root.left, list);
        list.add(root.val);
        in_order_traversal(root.right, list);
    }

    private TreeNode rebuild(List<Integer> list, int l, int r){
        if(l>r) return null;
        int m = (r - l) / 2 + l;
        System.out.println(m);
        TreeNode root = new TreeNode(list.get(m));
        root.left = rebuild(list, l, m-1);
        root.right = rebuild(list, m+1, r);

        return root;
    }
}

// TC: O(n)
// SC: O(n)
