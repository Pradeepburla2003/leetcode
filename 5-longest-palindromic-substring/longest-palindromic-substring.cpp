class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int maxlen = 0;
        int n = s.size();
        for(int i=0;i<s.size();i++){
            int l = i,r = i;
            while(l>=0 && r<n && s[l] == s[r]){
                if(r-l+1>maxlen){
                    maxlen = r-l+1;
                    res = s.substr(l,maxlen);
                }
                l-=1;
                r+=1;
            }
            l = i,r = i+1;
             while(l>=0 && r<n && s[l] == s[r]){
                if(r-l+1>maxlen){
                    maxlen = r-l+1;
                    res = s.substr(l,maxlen);
                }
                l-=1;
                r+=1;
            }
            // cout<<res<<endl;
        }
        return res;
    }
};
