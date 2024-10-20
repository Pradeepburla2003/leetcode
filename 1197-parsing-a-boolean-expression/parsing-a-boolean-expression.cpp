class Solution {
public:
    bool parseBoolExpr(string expression) {
        string s = "";
        stack<char>st;
        for(int i=0; i<expression.size(); i++){
            if(expression[i] == '|' or expression[i] == '!' or expression[i] == '&') s += expression[i];
            else if(expression[i] == ')'){
                bool res = false;
                if(s[s.size()-1] == '&'){
                    res = true;
                    cout<<"&"<<endl;
                    while(!st.empty() && st.top() != '('){
                        if(st.top() == 'f') res = false;
                        cout<<st.top()<<endl;
                        st.pop();
                    }
                }
                else if(s[s.size()-1] == '|'){
                    cout<<"|"<<endl;
                    while(!st.empty() && st.top() != '('){
                        if(st.top() == 't') res = true;
                        cout<<st.top()<<endl;
                        st.pop();
                    }
                }
                else{
                    if(st.top() == 't') res = false;
                    else res = true;
                    st.pop();
                }
                st.pop();
                // cout<<res<<"\n\n";
                if(res) st.push('t');
                else st.push('f');
                s.pop_back();
            }
            else{
                if(expression[i] != ',') st.push(expression[i]);
            }
        }
        if(st.top() == 't') return true;
        return false;
        // return st.top();
    }
};