class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        string ans = "";
        for(int j=0;j<s.size();j++){
            if(i<spaces.size() && spaces[i] == j){
                ans+=" ";
                i++;
            }
            ans += s[j];
        }
        return ans;
    }
};