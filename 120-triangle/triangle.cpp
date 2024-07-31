class Solution {
public:
    int fun(vector<vector<int>>& triangle,int i,int j,int n,vector<vector<int>>&dp){
        if(i==n or j>=triangle[i].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int pick=triangle[i][j]+fun(triangle,i+1,j,n,dp);
        int nonpick=triangle[i][j]+fun(triangle,i+1,j+1,n,dp);
        return dp[i][j]=min(pick,nonpick);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        return fun(triangle,0,0,triangle.size(),dp);
    }
};