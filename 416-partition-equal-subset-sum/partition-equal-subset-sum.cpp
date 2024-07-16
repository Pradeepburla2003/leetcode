class Solution {
public:
    bool fun(vector<int>&nums,vector<vector<int>>&dp,int i,int n,int res,int sum){
        if(i==n or res>sum) return 0;
        if(sum==res) return 1;
        if(dp[i][res]!=-1) return dp[i][res];
        bool pick=fun(nums,dp,i+1,n,res+nums[i],sum);
        bool nonpick=fun(nums,dp,i+1,n,res,sum);
        return dp[i][res]=pick|nonpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2) return 0;
        sum=sum/2;
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        return fun(nums,dp,0,n,0,sum);
    }
};