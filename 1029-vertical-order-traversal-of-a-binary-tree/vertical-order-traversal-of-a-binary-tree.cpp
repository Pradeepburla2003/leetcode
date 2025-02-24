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
    map<int,map<int,vector<int>>>temp;
    void dfs(TreeNode* root,int pos,int level){
        if(!root) return;
        temp[pos][level].push_back(root->val);
        dfs(root->left,pos-1,level++);
        dfs(root->right,pos+1,level++);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>>ans;
        for(auto i:temp){
            vector<int>dummy;
            for(auto j:i.second){
                vector<int>vc(j.second.begin(),j.second.end());
                sort(vc.begin(),vc.end());
               dummy.insert(dummy.end(), vc.begin(), vc.end());
            }
            ans.push_back(dummy);
        }
    
        return ans;
    }
};