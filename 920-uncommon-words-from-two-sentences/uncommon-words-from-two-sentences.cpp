class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        istringstream iss1(s1);
        istringstream iss2(s2);
        string word;
        map<string,int>mp;
        vector<string>ans;
        while(iss1 >> word){
            mp[word]++;
        }
        while(iss2 >> word){
            mp[word]++;
        }
        for(auto i:mp){
            if(i.second==1) ans.push_back(i.first);
        }
        return ans;
    }
};