class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>st;
        string ans="",temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(temp);
                temp="";
            }
            else if(s[i]==')'){
                if(st.size()>0){
                    ans=st.top();
                    st.pop();
                }
                reverse(temp.begin(),temp.end());
                ans+=temp;
                temp=ans;
                ans="";
            }
            else{
                temp+=s[i];
            }
        }
        return temp;
    }
};