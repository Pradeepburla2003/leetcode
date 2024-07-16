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
    TreeNode* fun(TreeNode* root, int startValue, int destValue){
        if(!root or root->val==startValue or root->val==destValue) return root;
        TreeNode* left=fun(root->left,startValue,destValue);
        TreeNode* right=fun(root->right,startValue,destValue);
        if(!left) return right;
        if(!right) return left;
        return root;
    }
    int dir(TreeNode* ancestor,int start,int count){
        if(!ancestor) return 0;
        if(ancestor->val==start) return count;
        int left=dir(ancestor->left,start,count+1);
        if(left) return left;
        int right=dir(ancestor->right,start,count+1);
        return right;
    }
    string ans="";
    void rem(TreeNode* root,int endvalue,string& temp){
        if(!root) return;
        if(root->val==endvalue){
            ans+=temp;
            return;
        }
        temp.push_back('L');
        rem(root->left,endvalue,temp);
        temp.pop_back();
        temp.push_back('R');
        rem(root->right,endvalue,temp);
         temp.pop_back();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* ancestor=fun(root,startValue,destValue);
        if(ancestor->val!=startValue and ancestor->val!=destValue){
            int count=dir(ancestor,startValue,0);
            string temp(count,'U');
            ans+=temp;
            string res;
            rem(ancestor,destValue,res);
            return ans;
        }
        else if(startValue==ancestor->val){
            string res;
            rem(ancestor,destValue,res);
        }
        else{
            int count=dir(ancestor,startValue,0);
            string temp(count,'U');
            ans+=temp;
        }
        return ans;
    }
};