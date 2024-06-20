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
        cout<<root->val<<" ";
        temp[pos][level].push_back(root->val);
        dfs(root->left,pos-1,level++);
        dfs(root->right,pos+1,level++);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root,0,0);
        vector<vector<int>>ans;
        for(auto i:temp){
            // sort(i.second.begin(),i.second.end());
            vector<int>dummy;
            for(auto j:i.second){
                sort(j.second.begin(),j.second.end());
                dummy.insert(dummy.end(),j.second.begin(),j.second.end());
            }
            ans.push_back(dummy);
        }
    
        return ans;
    }
};