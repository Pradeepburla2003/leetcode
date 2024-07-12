class Solution {
public:
    int fun(string word1, string word2,int i,int j,vector<vector<int>>&dp){
        if(j==word2.size()) return word1.size()-i;
        if(i==word1.size()) return word2.size()-j;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]){
            return fun(word1,word2,i+1,j+1,dp);
        }
        else{
            int in=1+fun(word1,word2,i,j+1,dp);
            int de=1+fun(word1,word2,i+1,j,dp);
            int re=1+fun(word1,word2,i+1,j+1,dp);
            return dp[i][j]=min(in,min(de,re));
        }
    }     
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return fun(word1,word2,0,0,dp);
    }
};