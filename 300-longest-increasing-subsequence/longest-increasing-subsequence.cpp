class Solution {
public:
    int help(vector<int>&nums,int j,int i,vector<vector<int>>&dp){
        if(i >= nums.size()) return 0;
        if(dp[i][j+1] != -1) return dp[i][j+1];
        int pick = 0;
        if(j==-1 || nums[i] > nums[j]) pick = 1 + help(nums,i,i+1,dp);
        int nonpick = help(nums,j,i+1,dp);
        return dp[i][j+1] = max(pick,nonpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size(),-1));
        return help(nums,-1,0,dp);
    }
};