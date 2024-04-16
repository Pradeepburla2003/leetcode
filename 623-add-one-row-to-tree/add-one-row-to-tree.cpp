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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        TreeNode* temp=root;
        queue<TreeNode*>q;
        q.push(temp);
        int c=1,size;
        if(depth==1){
            TreeNode* nn=new TreeNode(val);
            nn->left=root;
            return nn;
        }
        while(!q.empty()){
            size=q.size();
            if(c==depth-1){
                for(int i=0;i<size;i++){
                    TreeNode* dummy=q.front();
                    q.pop();
                    TreeNode *ll=new TreeNode(-111);
                    TreeNode *rr=new TreeNode(-111);
                    if(dummy->left) ll=dummy->left;
                    if(dummy->right) rr=dummy->right;
                    TreeNode* Left=new TreeNode(val);
                    TreeNode* Right=new TreeNode(val);
                    dummy->left=Left;
                    dummy->right=Right;
                    if(ll->val!=-111) dummy->left->left=ll;
                    if(rr->val!=-111) dummy->right->right=rr;
                }
                break;
            }
            for(int i=0;i<size;i++){
                TreeNode* dummy=q.front();
                q.pop();
                if(dummy->left) q.push(dummy->left);
                if(dummy->right) q.push(dummy->right);
            }
            c+=1;
        }
        return root;
    }
};