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
    bool isSame(TreeNode* root1,TreeNode* root2){
        if(!root1 && !root2) return true;
        if((root1 && !root2) or (!root1 && root2) or (root1->val!=root2->val)) return false;
        bool left = isSame(root1->left,root2->left);
        bool right = isSame(root1->right,root2->right);
        return (left && right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        cout<<root->val;
        if(isSame(root,subRoot)) return true;
        return (isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot));
    }
};