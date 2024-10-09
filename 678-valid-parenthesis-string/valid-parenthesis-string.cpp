class Solution {
public:
    bool help(string s,int i,int open,vector<vector<int>>&dp){
        if(open<0) return false;
        if(i==s.size()) return (open==0);
        if(dp[i][open] != -1) return dp[i][open];
        if(s[i]=='(') return dp[i][open] = help(s,i+1,open+1,dp);
        else if(s[i]==')') return dp[i][open] = help(s,i+1,open-1,dp);
        else{
            return dp[i][open] = help(s,i+1,open+1,dp) || help(s,i+1,open-1,dp) || help(s,i+1,open,dp);
        }
    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),-1));
        return help(s,0,0,dp);
    }
};