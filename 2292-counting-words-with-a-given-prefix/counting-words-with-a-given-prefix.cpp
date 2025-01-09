class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int size=pref.size();
        int ans=0;
        for(int i=0;i<words.size();i++){
            if(words[i].size()<size) continue;
            string temp=words[i].substr(0,size);
            if(temp==pref) ans++;
        }
        return ans;
    }
};