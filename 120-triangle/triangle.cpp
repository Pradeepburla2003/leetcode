class Solution {
public:
    int help(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>& dp){
        if(i >= triangle.size() or j >= triangle.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int left = triangle[i][j] + help(triangle,i+1,j,dp);
        int right = triangle[i][j] + help(triangle,i+1,j+1,dp);
        return dp[i][j] = min(left,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        return help(triangle,0,0,dp);
    }
};