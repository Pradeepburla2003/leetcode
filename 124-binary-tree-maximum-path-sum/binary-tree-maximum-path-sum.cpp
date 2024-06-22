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
    int ans=INT_MIN,edge=INT_MIN;
    int fun(TreeNode* root){
        if(!root)return 0;
        // if(root->left==NULL and root->right==NULL)return root->val;
         edge=max(edge,root->val);
        int left=fun(root->left);
        int right=fun(root->right);
        ans=max(ans,max(left,right));
        // ans=max(ans,left+right);
        ans=max(ans,max(root->val+left+right,root->val));
        cout<<ans<<endl;
        return max(0,max(left,right)+root->val);
        
    }
    int maxPathSum(TreeNode* root) {
        int temp = fun(root);
        if(edge>INT_MIN && edge<0) return edge;
        return ans;
    }
};