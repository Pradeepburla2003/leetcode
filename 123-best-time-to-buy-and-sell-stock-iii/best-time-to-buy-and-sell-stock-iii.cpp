class Solution {
public:
    int help(vector<int>& prices,int buy,int ind,int cap,int n,vector<vector<vector<int>>>& dp){
        if(ind == n or cap == 0) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap]; 
        if(buy){
            return dp[ind][buy][cap] = max(-prices[ind] + help(prices,0,ind+1,cap,n,dp),0 + help(prices,1,ind+1,cap,n,dp));
        }
        else{
            return dp[ind][buy][cap] = max(prices[ind] + help(prices,1,ind+1,cap-1,n,dp),0 + help(prices,0,ind+1,cap,n,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return help(prices,1,0,2,n,dp);
    }
};