class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string>ans;
        sort(folder.begin(),folder.end());
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            cout<<ans.size()<<" ";
            string s = ans.back();
            cout<<ans.size()<<endl;
            int flag = 0;
            if(s.size() > folder[i].size()) ans.push_back(folder[i]);
            else{
                for(int j=0;j<s.size();j++){
                    if(s[j]!=folder[i][j]){
                        ans.push_back(folder[i]);
                        break;
                    }
                }
                if(s.size()!=folder[i].size() && folder[i][s.size()]!='/') ans.push_back(folder[i]);
            }
        }
        return ans;
    }
};