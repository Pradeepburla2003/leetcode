class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') c+=1;
        }
        string ans="";
        for(int i=0;i<c-1;i++){
            ans+='1';
        }
        for(int i=0;i<s.size()-c;i++){
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};