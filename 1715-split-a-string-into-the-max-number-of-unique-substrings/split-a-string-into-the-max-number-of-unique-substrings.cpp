class Solution {
public:
    void help(string s,int i,map<string,int>&mp,int &ans){
        if(i == s.size()){
            int size = mp.size();
            ans = max(ans,size);
            return;
        }
        string temp = "";
        for(int j = i; j < s.size();j++){
            temp += s[j];
            if(mp.find(temp) == mp.end()){
                mp[temp]++;
                help(s,j+1,mp,ans);
                mp[temp]--;
                if(mp[temp] == 0) mp.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int ans = 0;
        map<string,int>mp;
        help(s,0,mp,ans);
        return ans;
    }
};