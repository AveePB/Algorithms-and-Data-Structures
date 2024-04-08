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
    List<Integer> res = new ArrayList<>();

    void travelAndMark(TreeNode t) {
        if(t == null)
            return;

        travelAndMark(t.left);
        this.res.add(t.val);
        travelAndMark(t.right);

    }
    public List<Integer> inorderTraversal(TreeNode root) {
        travelAndMark(root);
        return this.res;    
    }
}
