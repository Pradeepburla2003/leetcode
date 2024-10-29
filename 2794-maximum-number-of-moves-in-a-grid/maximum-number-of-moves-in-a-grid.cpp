class Solution {
public:
    int help(vector<vector<int>>& grid,int i,int j,int prev,vector<vector<int>>& dp){
        if(i >= grid.size() or i < 0 or j >= grid[0].size() or prev >= grid[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int back = 1 + help(grid,i-1,j+1,grid[i][j],dp);
        int right = 1 + help(grid,i,j+1,grid[i][j],dp);
        int front = 1 + help(grid,i+1,j+1,grid[i][j],dp);
        return dp[i][j] = max(back,max(right,front));
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            ans = max(ans,help(grid,i,0,0,dp)-1);
        }
        return ans;
    }
};