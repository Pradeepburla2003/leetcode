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
    bool ans=true;
    long long prev=-1e11;
    void fun(TreeNode* root){
        if(!root) return;
        fun(root->left);
        // cout<<prev<< " "<<root->val<<endl;
        if(prev>=root->val){
            ans=false;
            // return;
        }
        else prev=root->val+0LL;
        
        fun(root->right);
    }
    bool isValidBST(TreeNode* root) {
        fun(root);
        return ans;
    }
};