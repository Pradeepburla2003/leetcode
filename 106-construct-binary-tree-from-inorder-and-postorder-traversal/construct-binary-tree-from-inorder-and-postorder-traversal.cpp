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
    TreeNode* fun(map<int,int>&inorder,vector<int>&postorder,int instart,int inend,int poststart,int postend){
        cout<<instart<<" "<<inend<<" "<<poststart<<" "<<postend<<endl;
        if(instart>inend or poststart>postend) return NULL;
        TreeNode* root=new TreeNode(postorder[postend]);
        int inroot=inorder[root->val];
        int side=inroot-instart;
        root->left=fun(inorder,postorder,instart,inroot-1,poststart,poststart+side-1);
        root->right=fun(inorder,postorder,inroot+1,inend,poststart+side,postend-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return fun(mp,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
};