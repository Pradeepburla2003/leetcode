class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(i==0) st.push(s[i]);
            else{
                if(st.size()>0 && (s[i]-'a'==st.top()-'A' or s[i]-'A'==st.top()-'a')){
                   
                    // cout<<1<<" "<<st.top()<<" "<<s[i]<<endl;
                     st.pop();
                }
                else{
                    st.push(s[i]);
                    // cout<<0<<" "<<s[i]<<endl;
                }
            }
        }
        string ans(st.size(),'0');
        int n=st.size();
        for(int i=n-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};