class Solution {
public:
    int fun(int i,int j,int m,int n,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(i==m-1 and j==n-1) return 1;
        if(i>=m or j>=n or obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int bottom=fun(i+1,j,m,n,obstacleGrid,dp);
        int right=fun(i,j+1,m,n,obstacleGrid,dp);
        // cout<<bottom<<" "<<right<<endl;
        return dp[i][j]=bottom+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(0,0,m,n,obstacleGrid,dp);

    }
};