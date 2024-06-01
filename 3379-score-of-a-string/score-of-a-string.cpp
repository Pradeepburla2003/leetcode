class Solution {
public:
    int scoreOfString(string s) {
        int ans=0,k1,k2;
        for(int i=1;i<s.size();i++){
            k1=s[i]-'a';
            k2=s[i-1]-'a';
            ans+=abs(k1-k2);
        }
        return ans;
    }
};