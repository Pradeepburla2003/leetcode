class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>>hash;
        int ans = 0;
        for(int i=0;i<words.size();i++){
            vector<int>temp(26);
            for(auto c:words[i]){
                temp[c-'a']++;
            }
            hash.push_back(temp);
        }
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                int flag = 0;
                for(int k=0;k<26;k++){
                    if(hash[i][k] && hash[j][k]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) ans = max(ans,(int)words[i].size() * (int)words[j].size());
            }
        }
        return ans;
    }
};