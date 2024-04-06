class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>st;
        int c1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='(' && s[i]!=')'){
                st.push(s[i]);
                // cout<<s[i]<<" ";
            }
            else if(s[i]=='('){
                st.push(s[i]);
                c1+=1;
                // cout<<s[i]<<" ";
            }
            else{
                if(s[i]==')' and c1>0){
                    st.push(s[i]);
                    // cout<<s[i]<<" ";
                    c1-=1;
                }  
            }
        }
        int i=st.size()-c1;
        // cout<<i<<c1;
        string ans(i,'0');
        i-=1;
        while(!st.empty()){
            if(st.top()==')' and c1==0){
                ans[i]=st.top();
                // cout<<ans[i]<<endl;
                 i-=1;
            }
            else if(st.top()=='(' and c1>0){
                c1-=1;
                // cout<<"bye"<<endl;
            }
            else{
                ans[i]=st.top();
                // cout<<"mowa"<<" "<<ans[i]<<endl;
                i-=1;
            }
            // cout<<st.top()<<" ";
            st.pop();
        }
        return ans;
    }
};