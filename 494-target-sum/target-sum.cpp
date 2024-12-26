class Solution {
public:
    int offset=1000;
    int fun(vector<int>&nums,int target,int i,int sum,vector<vector<int>>&dp,int n){
        if(sum==target and i==n) return 1;
        if(i>=n) return 0;
        if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];
        int plus=fun(nums,target,i+1,sum+nums[i],dp,n);
        int minus=fun(nums,target,i+1,sum-nums[i],dp,n);
        return dp[i][sum+offset]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(2001,-1));
        return fun(nums,target,0,0,dp,nums.size());
    }
};