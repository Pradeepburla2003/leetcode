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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int i=0,size;
        
        while(!q.empty()){
           size=q.size();
            vector<int>vec;
            for(int j=0;j<size;j++){
                TreeNode* temp=q.front();
                q.pop();
                if(i%2==0){
                    if(j==0){
                      if(temp->val%2==0){ cout<<"hi";
                                         return 0;  }
                    }
                    else if(temp->val%2==0 or (temp->val<=vec[vec.size()-1])) {
                        return 0;
                    }
                }
                else{
                    if(j==0){
                        if(temp->val%2==1){
                            return 0;
                        }
                    }
                   else if(temp->val%2==1 or (temp->val>=vec[vec.size()-1])) {
                       return 0; 
                   }
                }
                vec.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            i+=1;
        }
       return true; 
    }
};