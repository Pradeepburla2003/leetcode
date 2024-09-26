class Solution {
public:
    int help(vector<vector<int>>& obstacleGrid,int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i == m-1 && j == n-1) return 1;
        if(i >= m || j >= n || obstacleGrid[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int right = help(obstacleGrid,i,j+1,m,n,dp);
        int down = help(obstacleGrid,i+1,j,m,n,dp);
        // cout<<right<<" "<<down<<endl;
        return dp[i][j] = right + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(),n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return help(obstacleGrid,0,0,m,n,dp);
    }
};