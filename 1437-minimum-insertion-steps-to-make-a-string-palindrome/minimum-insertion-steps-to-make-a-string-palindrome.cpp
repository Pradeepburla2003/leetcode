class Solution {
public:
    int fun(string& s, string& rev,int i,int j,vector<vector<int>>&dp){
        if(i==s.size() or rev.size()==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==rev[j]){
            return dp[i][j]=1+fun(s,rev,i+1,j+1,dp);
        }
        else{
            return dp[i][j]=max(fun(s,rev,i,j+1,dp),fun(s,rev,i+1,j,dp));
        }
    }
    int minInsertions(string s) {
        string rev(s.rbegin(),s.rend());
         vector<vector<int>>dp(s.size(),vector<int>(rev.size(),-1));
        return s.size()-fun(s,rev,0,0,dp);
    }
};