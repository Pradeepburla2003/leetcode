class Solution {
public:
    int fun(vector<int>&nums,int amount,int i,vector<vector<int>>&dp){

        if(amount==0) return amount;
        if(amount<0 or i==nums.size()) return  100000;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=1+fun(nums,amount-nums[i],i,dp);
        int nonpick=fun(nums,amount,i+1,dp);
        // cout<<pick<<" "<<nonpick<<endl;
        return dp[i][amount]=min(pick,nonpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(10002,-1));
        int ans=fun(coins,amount,0,dp);
        if(ans>=100000) return -1;
        return ans;
    }
};