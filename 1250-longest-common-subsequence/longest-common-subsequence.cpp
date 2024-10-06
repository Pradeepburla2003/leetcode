class Solution {
public:
    int help(string text1, string text2,int i,int j,vector<vector<int>>&dp){
        if(i>=text1.size() || j>=text2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + help(text1,text2,i+1,j+1,dp);
        }
        else{
            return dp[i][j] = max(help(text1,text2,i+1,j,dp),help(text1,text2,i,j+1,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,0));
        int m = text1.size(),n=text2.size();
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
        return help(text1,text2,0,0,dp);
    }
};