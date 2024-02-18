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
    TreeNode* fun(vector<int>&nums,int i,int j)
    {
        if(i>j)return NULL;
        int m=(i+j)/2;
        TreeNode *nn=new TreeNode(nums[m]);
        nn->left=fun(nums,i,m-1);
        nn->right=fun(nums,m+1,j);
        return nn;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return fun(nums,0,nums.size()-1);

    }
};