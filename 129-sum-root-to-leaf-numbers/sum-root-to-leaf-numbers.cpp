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
    void dfs(TreeNode* root,int sum){
        if(!root) return;
        if(!root->left && !root->right){
            cout<<sum<<endl;
            sum=sum*10+root->val;
            ans+=sum;
            return;
        }
        sum=sum*10+root->val;
        dfs(root->left,sum);
        dfs(root->right,sum);
        sum=sum/10;
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};