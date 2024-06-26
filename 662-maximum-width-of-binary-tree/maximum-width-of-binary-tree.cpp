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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned int maxi=1;
        queue<pair<TreeNode*,unsigned int>>q;
        q.push({root,1});
        // cout<<q.front().first->val<<<<q.front().second;
        while(!q.empty()){
            unsigned int size=q.size(),count=0;
            unsigned int start=q.front().second;
            cout<<start<<endl;
            for(int i=0;i<size;i++){
                pair<TreeNode*,unsigned int>temp=q.front();
                if(i==size-1){
                    count=q.front().second-start+1;
                }
                q.pop();
                if(temp.first->left){
                    q.push({temp.first->left,2*temp.second});
                }
                if(temp.first->right){
                    q.push({temp.first->right,(2*temp.second)+1});
                }
            }
            // cout<<count<<" ";
            maxi=max(maxi,count);
        }
        return maxi;
    }
};