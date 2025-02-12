class Solution {
public:
    void help(vector<int>& candidates,int i,int target,vector<int>& temp,set<vector<int>>&st){
        if(target==0){
            st.insert(temp);
            return;
        }
        for(int j=i;j<candidates.size();j++){
            if(target-candidates[j]>=0){
                temp.push_back(candidates[j]);
                help(candidates,j,target-candidates[j],temp,st);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>st;
        vector<int>temp;
        help(candidates,0,target,temp,st);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};