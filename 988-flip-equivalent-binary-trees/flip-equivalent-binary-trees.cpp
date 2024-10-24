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
    string help(TreeNode* root,vector<string>&vc){
        if(!root){
            return "N";
        }
        string s = to_string(root->val) + help(root->left,vc);
        s += help(root->right,vc);
        sort(s.begin(),s.end());
        vc.push_back(s);
        return s;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        vector<string>v1,v2;
        string s = help(root1,v1);
        s = help(root2,v2);
        if(v1.size() != v2.size()) return false;
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(int i=0;i<v1.size();i++){
            if(v1[i] != v2[i]) return false;
        }
        return true;
    }
};