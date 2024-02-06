class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        string sam="";
        vector<string>sub;
        for(int i=0;i<strs.size();i++){
            sub.push_back(strs[i]);
            sort(strs[i].begin(),strs[i].end());
        }
        string flag="1234";
        for(int i=0;i<strs.size();i++){
            sam=strs[i];
            vector<string>l;
            l.push_back(sub[i]);
            if(sam!=flag)
            {
                for(int j=i+1;j<strs.size();j++){
                    if(sam==strs[j]){
                        l.push_back(sub[j]);
                        strs[j]=flag;
                    }
                }
                ans.push_back(l);
            }
        }
        return ans;
    }
};