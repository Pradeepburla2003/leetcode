class Solution {
public:
    bool possible(string &s){
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int help(int i,int n,string &s,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        string temp="";
        int min_cost=INT_MAX;
        for(int j=i;j<n;j++){
            temp+=s[j];
            if(possible(temp)){
                int cost=1+help(j+1,n,s,dp);
                min_cost=min(min_cost,cost);
            }
        }
        return dp[i]=min_cost;
    }
    int minCut(string s) {
        vector<int>dp(s.size(),-1);
        return help(0,s.size(),s,dp)-1;
    }
};