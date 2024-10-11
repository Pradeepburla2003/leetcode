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
    long long prev=-1e11;
    bool fun(TreeNode* root){
        if (!root) return true;
        if (!fun(root->left)) return false;
        if (prev >= root->val) return false;
        prev = root->val;
        return fun(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return fun(root);
    }
};