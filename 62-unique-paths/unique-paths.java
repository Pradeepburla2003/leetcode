class Solution {
    public int help(int i,int j,int m,int n,int[][] dp){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left = help(i+1,j,m,n,dp);
        int right = help(i,j+1,m,n,dp);
        return dp[i][j] = left+right;
    }
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[101][101];
        for (int i = 0; i < 101; i++) {
            Arrays.fill(dp[i], -1);
        }
        return help(0,0,m,n,dp);
    }
}