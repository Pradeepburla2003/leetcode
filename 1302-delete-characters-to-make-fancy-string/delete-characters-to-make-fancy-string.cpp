class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int i = 0;
        while(i<s.size()){
            int count = 0;
            while(i+1<s.size() && s[i]==s[i+1]){
                count++;
                i++;
            }
            ans += s[i];
            if(count>=1) ans += s[i];
            i++;
        }
        return ans;
    }
};