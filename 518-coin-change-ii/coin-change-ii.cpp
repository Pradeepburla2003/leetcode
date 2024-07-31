class Solution {
public:
    int fun(int amount,vector<int>&coins,int i,vector<vector<int>>&dp){
        if(i>=coins.size() or amount<0) return 0;
        if(amount==0) return 1;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=fun(amount-coins[i],coins,i,dp);
        int nonpick=fun(amount,coins,i+1,dp);
        return dp[i][amount]=pick+nonpick;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return fun(amount,coins,0,dp);
    }
};