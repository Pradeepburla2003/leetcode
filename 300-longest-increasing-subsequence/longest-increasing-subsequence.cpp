class Solution {
public:
    int ans=1;
    int fun(vector<int>&nums,int i,int j,int n,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][j+1]!=-1) return dp[i][j+1];
        int pick=0;
        if(j==-1 or nums[i]>nums[j]){
            pick=1+fun(nums,i+1,i,n,dp);
        }
        int nonpick=fun(nums,i+1,j,n,dp);
        return dp[i][j+1]=max(pick,nonpick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return fun(nums,0,-1,nums.size(),dp);
    }
};