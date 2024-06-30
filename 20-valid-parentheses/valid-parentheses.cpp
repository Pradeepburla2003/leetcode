class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2) return 0;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') st.push(')');
            else if(s[i]=='[') st.push(']');
            else if(s[i]=='{') st.push('}');
            else if(st.size()>0 and s[i]==st.top()) st.pop();
            else return 0;
        }
        if(st.size()>0) return 0;
        return 1;
    }
};