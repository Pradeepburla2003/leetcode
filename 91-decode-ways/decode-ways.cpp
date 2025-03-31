class Solution {
public:
    int help(string s,int i,int n,vector<int>&dp){
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int onepick=help(s,i+1,n,dp);
        int twopick=0;
        if(i+1<n && (s[i]=='1' or (s[i]=='2' && s[i+1]<='6')))
            twopick=help(s,i+2,n,dp);
        return dp[i]=onepick+twopick;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return help(s,0,n,dp);
    }
};