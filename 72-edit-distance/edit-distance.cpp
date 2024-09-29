class Solution {
public:
    int help(string word1, string word2,int i,int j,int m,int n,vector<vector<int>>&dp){
        if(i == m) return n - j;
        if(j == n) return m - i;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]){
            return help(word1,word2,i+1,j+1,m,n,dp);
        }
        else{
            int insert = 1 + help(word1,word2,i,j+1,m,n,dp);
            int remove = 1 + help(word1,word2,i+1,j,m,n,dp);
            int replace = 1 + help(word1,word2,i+1,j+1,m,n,dp);
            return dp[i][j] = min(insert,min(replace,remove));
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return help(word1,word2,0,0,m,n,dp);
    }
};