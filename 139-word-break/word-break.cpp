class Solution{
private:
    bool solve(int ind,string &s,int str_len,unordered_map<string,int> &mp,vector<int> &dp){
        if(ind==str_len)
            return true;
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        for(int i=ind;i<str_len;i++){
            if(mp.find(s.substr(ind,i-ind+1))!=mp.end()){
                if(solve(i+1,s,str_len,mp,dp))
                    return dp[ind]=true;
            }
        }
        return dp[ind]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size=wordDict.size();
        unordered_map<string,int> mp;
        for(int i=0;i<size;i++)
            mp[wordDict[i]]=1;
        int str_len=s.size();
        vector<int> dp(str_len+1,-1);
        return solve(0,s,str_len,mp,dp);
    }
};