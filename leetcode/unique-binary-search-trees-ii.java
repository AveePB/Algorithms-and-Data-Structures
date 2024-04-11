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
    private List<TreeNode> backtracking(int l, int r) {
        List<TreeNode> res = new ArrayList<>();
        if (l > r) {
            res.add(null);
            return res;
        }

        for (int i=l; i<=r; i++) {
           List<TreeNode> left = backtracking(l, i-1);
           List<TreeNode> right = backtracking(i+1, r);

           for (TreeNode left_son: left) {
               for (TreeNode right_son: right) {
                   TreeNode root = new TreeNode(i);
                   root.left = left_son;
                   root.right = right_son;
                   res.add(root);
               }
           }
        }
        return res;
    }

    public List<TreeNode> generateTrees(int n) {
        if(n == 0) return new ArrayList<>();
        return backtracking(1, n);
    }
}
