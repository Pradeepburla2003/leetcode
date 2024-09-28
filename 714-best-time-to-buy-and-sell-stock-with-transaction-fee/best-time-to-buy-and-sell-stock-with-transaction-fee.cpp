class Solution {
public:
    int help(vector<int>& prices,int buy,int ind,int n,vector<vector<int>>& dp,int fee){
        if(ind == n) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy]; 
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + help(prices,0,ind+1,n,dp,fee),0 + help(prices,1,ind+1,n,dp,fee));
        }
        else{
            profit = max(prices[ind] + help(prices,1,ind+1,n,dp,fee) - fee,0 + help(prices,0,ind+1,n,dp,fee));
        }
        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return help(prices,1,0,n,dp,fee);
    }
};