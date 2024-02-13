class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int j,k,l;
        for(int i=0;i<words.size();i++){
            l=0,j=0,k=words[i].size()-1;
            while(j<k){
                if(words[i][j]!=words[i][k]){
                    l=1;
                    break;
                }
                j+=1;
                k-=1;
            }
            if(l==0) return words[i];
        }
        return "";
    }
};