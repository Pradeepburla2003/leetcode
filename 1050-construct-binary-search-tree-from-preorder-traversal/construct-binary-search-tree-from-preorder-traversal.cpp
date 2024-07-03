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
    TreeNode* ans(map<int,int>&mp,vector<int>&preorder,int instart,int inend,int prestart,int preend){
        if(instart>inend or prestart>preend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot=mp[root->val];
        cout<<root->val<<" ";
        int left=inroot-instart;
        root->left=ans(mp,preorder,instart,inroot-1,prestart+1,prestart+left);
        root->right=ans(mp,preorder,inroot+1,inend,prestart+left+1,preend);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder(preorder.begin(),preorder.end());
        sort(inorder.begin(),inorder.end());
        map<int,int>mp;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return ans(mp,preorder,0,n-1,0,n-1);
    }
};