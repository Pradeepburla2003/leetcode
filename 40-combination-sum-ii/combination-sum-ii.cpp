class Solution {
public:
    void fun(vector<int>& candidates, int target,int sum,set<vector<int>>&s,int i,int n,vector<int>&temp){
        if(sum==target){
            s.insert(temp);
            return;
        }
        for(int j=i;j<n;j++){
            if(j!=i && candidates[j]==candidates[j-1]) continue;
            if(sum>target) break;
            temp.push_back(candidates[j]);
            fun(candidates,target,sum+candidates[j],s,j+1,n,temp);
            temp.pop_back();
        }
     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>s;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        fun(candidates,target,0,s,0,candidates.size(),temp);
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};