class Solution {
public:
    void fun(string s,int ind,int n,vector<string>&temp,vector<vector<string>>&ans){
        if(ind==n){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<n;i++){
            if(ispalindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                fun(s,i+1,n,temp,ans);
                temp.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int ind,int n){
        while(ind<n){
            if(s[ind++]!=s[n--]) return 0;
        }
        return 1;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        fun(s,0,s.size(),temp,ans);
        return ans;
    }
};