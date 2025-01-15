class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0,open=0,close=0;
        for(auto i:s){
            if(i=='(') open++;
            else close++;
            if(open==close) ans=max(ans,2*open);
            else if(close>open) open=close=0;
        }
        open=0,close=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(open==close) ans=max(ans,2*open);
            else if(open>close) open=close=0;
        }
        // ans=max(ans,temp);
        return ans;
    }
};