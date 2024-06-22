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
    int ans=0;
    int fun(TreeNode* root){
        if(!root) return 0;
        int left=max(0,fun(root->left));
        int right=max(0,fun(root->right));
        ans=max(ans,left+right+1);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // if(!root) return 0;
        int temp=fun(root);
        return ans-1;
    }
};