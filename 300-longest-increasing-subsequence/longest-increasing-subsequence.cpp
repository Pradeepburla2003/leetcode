class Solution {
public:
    int help(vector<int>&nums,int i,int j,vector<vector<int>>&dp){
        if(i >= nums.size()) return 0;
        if(dp[i][j+1] != -1) return dp[i][j+1];
        int pick = 0;
        if(j==-1 || nums[i] > nums[j]) pick = 1 + help(nums,i+1,i,dp);
        int nonpick = help(nums,i+1,j,dp);
        return dp[i][j+1] = max(pick,nonpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
        int res = help(nums,0,-1,dp);
        int n = nums.size();
        // return res;
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int pick = 0;
                if(j==-1 || nums[i] > nums[j]) pick = 1 + dp[i+1][i+1];
                int nonpick = dp[i+1][j+1];
                dp[i][j+1] = max(pick,nonpick);
            }
        }
        return dp[0][0];
    }
};