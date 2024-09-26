class Solution {
public:
    int help(vector<int>& coins,int i, int amount,vector<vector<int>>&dp){
        if(amount == 0) return 0;
        if(i >= coins.size() || amount < 0) return 1e8;
        if(dp[i][amount] != -1) return dp[i][amount];
        int pick = INT_MAX;
        if(coins[i] <= amount) pick = 1 + help(coins,i,amount - coins[i],dp);
        int nonpick = help(coins,i+1,amount,dp);
        return dp[i][amount] = min(pick,nonpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<vector<int>>dp(coins.size(),vector<int>(10002,-1));
        int ans = help(coins,0,amount,dp);
        if(ans >= 1e8) return -1;
        return ans;
    }
};