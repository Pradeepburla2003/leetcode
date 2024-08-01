class Solution {
public:
    int fun(string &s,string &t,int i,int j,vector<vector<int>>&dp){
        if(j==t.size()) return 1;
        if(i>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int pick=0,nonpick=0,result=0;
        if(s[i]==t[j]){
            pick=fun(s,t,i+1,j+1,dp);
            nonpick=fun(s,t,i+1,j,dp);
            result=pick+nonpick;
        }
        else result=fun(s,t,i+1,j,dp);
        return dp[i][j]=result;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return fun(s,t,0,0,dp);
    }
};