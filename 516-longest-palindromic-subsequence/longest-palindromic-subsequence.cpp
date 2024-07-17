class Solution {
public:
    int sub(string& s,string& rev,int i,int j,vector<vector<int>>&dp){
        if(i>=s.size() or j>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==rev[j]){
            return dp[i][j]=1+sub(s,rev,i+1,j+1,dp);
        }
        else{
            return dp[i][j]=max(sub(s,rev,i+1,j,dp),sub(s,rev,i,j+1,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        string rev(s.rbegin(),s.rend());
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return sub(s,rev,0,0,dp);
    }
};