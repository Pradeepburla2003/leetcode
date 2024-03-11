class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']+=1;   
        }
        string ans="";
        for(int i=0;i<order.size();i++){
            while(freq[order[i]-'a']>0){
                ans+=order[i];
                freq[order[i]-'a']-=1;
            }
        }
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']>0) ans+=s[i];  
        }
        return ans;
    }
};