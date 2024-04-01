class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(count>0) ans=count;
                count=0;
            }
            else{
                count++;
            }
        }
        if(count>0) ans=count;
        return ans;
    }
};