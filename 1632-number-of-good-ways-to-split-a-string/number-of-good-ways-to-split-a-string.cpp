class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int>mp1,mp2;
        mp1[s[0]]++;
        int c=0;
        for(int i=1;i<s.size();i++)mp2[s[i]]++;
        for(int i=1;i<s.size();i++)
        {
            if(mp1.size()==mp2.size())c++;
            mp1[s[i]]++;
            mp2[s[i]]--;
            if(mp2[s[i]]==0)mp2.erase(s[i]);
        }
        return c;
    }
};