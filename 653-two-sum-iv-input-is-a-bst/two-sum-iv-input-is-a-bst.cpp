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
    bool flag=false;
    void fun(TreeNode* root,int k,set<int>&s){
        if(!root) return;
        if(s.find(k-root->val)!=s.end()){
            flag=true;
            return;
        }
        s.insert(root->val);
        fun(root->left,k,s);
        fun(root->right,k,s);
    }
    bool findTarget(TreeNode* root, int k) {
        set<int>s;
        fun(root,k,s);
        return flag;
    }
};