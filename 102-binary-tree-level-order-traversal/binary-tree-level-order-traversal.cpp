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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        vector<int>v;
        v.push_back(root->val);
        ans.push_back(v);
        while(!q.empty()){
            int size=q.size();
            vector<int>sub;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left){
                    sub.push_back(temp->left->val);
                    q.push(temp->left);
                }
                if(temp->right){
                    sub.push_back(temp->right->val);
                    q.push(temp->right);
                }
            }
            if(sub.size()>0) ans.push_back(sub);
        }
        return ans;
    }
};