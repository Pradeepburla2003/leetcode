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
    public TreeNode help(int[] nums,int i,int j){
        if(i>j) return null;
        int mid = (i+j)/2;
        TreeNode root = new TreeNode(nums[mid]);
        root.left=help(nums,i,mid-1);
        root.right=help(nums,mid+1,j);
        return root;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        return help(nums,0,nums.length-1);
    }
}