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
    bool fun(TreeNode* root,int k,set<int>&s){
        if(!root) return false;
        if(s.find(k-root->val)!=s.end()){
            return true;
        }
        s.insert(root->val);
        if(fun(root->left,k,s)) return true;
        if(fun(root->right,k,s)) return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        set<int>s;
        return fun(root,k,s);
        return flag;
    }
};