class Solution {
public:
    bool help(string &s,string &p,int i,int j,vector<vector<int>>&dp){
        if(j==p.size()) return (i==s.size());
        if(i==s.size()){
            for(int k=j;k<p.size();k++) if(p[k]!='*') return false;
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if((s[i]==p[j] or p[j]=='?')) return dp[i][j]=help(s,p,i+1,j+1,dp);
        if(p[j]=='*') return dp[i][j]=(help(s,p,i+1,j,dp) || help(s,p,i,j+1,dp));
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return help(s,p,0,0,dp);
    }
};