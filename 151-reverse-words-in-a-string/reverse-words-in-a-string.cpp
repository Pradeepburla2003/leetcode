class Solution {
public:
    string reverseWords(string s) {
        vector<string>s1;
        string temp="";
        int i=0,n=s.size();
        while(i<n){
            if(isalpha(s[i]) or isdigit(s[i])){
                while(i<n && (isalpha(s[i]) or isdigit(s[i]))){
                    cout<<s[i];
                    temp+=s[i++];
                }
                s1.push_back(temp);
                temp="";
            }
            else i++;
        }
        for(int i=s1.size()-1;i>0;i--){
            temp+=s1[i];
            temp+=" ";
        }
        temp+=s1[0];
        return temp;
    }
};