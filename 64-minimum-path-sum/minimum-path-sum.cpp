class Solution {
public:
    int fun(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==m-1 and j==n-1) return grid[i][j];
        if(i>=m or j>=n) return INT_MAX-1;
        if(dp[i][j]!=-1) return dp[i][j];
        int bottom=fun(i+1,j,m,n,grid,dp);
        int right=fun(i,j+1,m,n,grid,dp);
        return dp[i][j]=grid[i][j]+min(right,bottom);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(0,0,m,n,grid,dp);
    }
};