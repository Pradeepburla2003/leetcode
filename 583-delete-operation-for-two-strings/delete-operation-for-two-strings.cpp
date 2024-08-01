class Solution {
public:
    int fun(string word1,string word2,int i,int j,vector<vector<int>>&dp){
        if(i>=word1.size() or j>=word2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=1+fun(word1,word2,i+1,j+1,dp);
        }
        else{
            return dp[i][j]=max(fun(word1,word2,i+1,j,dp),fun(word1,word2,i,j+1,dp));
        }
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int lcs=fun(word1,word2,0,0,dp);
        return m+n-(2*lcs);
    }
};