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
    TreeNode* fun(vector<int>& preorder,map<int,int>&mp,int instart,int inend,int prestart,int preend){
        if(instart>inend or prestart>preend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot=mp[root->val];
        int l=inroot-instart;
        root->left=fun(preorder,mp,instart,inroot-1,prestart+1,preend);
        root->right=fun(preorder,mp,inroot+1,inend,prestart+1+l,preend);
        // if(root->right) prestart++;
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return fun(preorder,mp,0,inorder.size()-1,0,preorder.size()-1);
    }
};