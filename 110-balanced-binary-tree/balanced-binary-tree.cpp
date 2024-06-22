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
    // bool ans=true;
    int fun(TreeNode* root){
        if(!root) return 0;
        int left=fun(root->left);
        if(left==-1) return -1;
        int right=fun(root->right);
        if(right==-1) return -1;
        if(abs(left-right)>=2) return -1;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        return fun(root)!=-1;
    }
};