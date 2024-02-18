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
    int c=0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int a=1+dfs(root->left);
        int b=1+dfs(root->right);
        if(abs(a-b)>1) c=1;
        return max(a,b);
    }
    bool isBalanced(TreeNode* root) {
        int k=dfs(root);
        if(c) return 0;
        return 1;
    }
};