class Solution {
public:
    bool help(string &s,int i,map<string,int>&mp,string temp,vector<int>&dp){
        // cout<<temp<<" ";
        if(s.size()==i) return (s==temp);
        if(dp[i]!=-1) return dp[i];
        string word="";
        // cout<<word<<" "
        for(int j=i;j<s.size();j++){
            word+=s[j];
            if(mp.find(word)!=mp.end()){
                bool found = help(s,j+1,mp,temp+word,dp);
                if(found) return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,int>mp;
        for(int i=0;i<wordDict.size();i++) mp[wordDict[i]]++;
        string temp="",word="";
        vector<int>dp(s.size(),-1);
        return help(s,0,mp,temp,dp);
    }
};