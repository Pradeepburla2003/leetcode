/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void help(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto current=q.front();
            q.pop();
            if(current->left){
                q.push(current->left);
                parent[current->left]=current;
            }
            if(current->right){
                q.push(current->right);
                parent[current->right]=current;
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        unordered_map<TreeNode*,bool>vis;
        help(root,parent);
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=true;
        int lev=0;
        while(!q.empty()){
            if(lev++==k) break;
            int size=q.size();
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }
                if(parent[node] && !vis[parent[node]]){
                    vis[parent[node]]=true;
                    q.push(parent[node]);
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            auto cur=q.front();q.pop();
            res.push_back(cur->val);
        }
        return res;
    }
};