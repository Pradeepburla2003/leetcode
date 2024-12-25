class Solution {
public:
    string reverseVowels(string s) {
        string vowels="";
        for(int i=0;i<s.size();i++){
            char ch = tolower(s[i]);
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u') vowels+=s[i];
        }
        int j=0;
        for(int i=s.size()-1;i>=0;i--){
            char ch = tolower(s[i]);
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u') s[i]=vowels[j++];
        }
        return s;
    }
};