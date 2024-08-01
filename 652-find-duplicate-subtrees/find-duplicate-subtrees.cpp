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
    string fun(TreeNode* root,map<string,int>&mp,vector<TreeNode*>&ans){
        if(!root) return "N";
        string s1=to_string(root->val)+" "+fun(root->left,mp,ans);
        s1+=" "+fun(root->right,mp,ans);
        mp[s1]++;
        cout<<s1<<endl;
        if(mp[s1]==2) ans.push_back(root);
        return s1;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        map<string,int>mp;
        vector<TreeNode*>ans;
        string s=fun(root,mp,ans);
        // cout<<s<<endl;
        return ans;
    }
};