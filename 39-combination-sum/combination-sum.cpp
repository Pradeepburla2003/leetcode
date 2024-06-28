class Solution {
public:
    void fun(vector<int>& candidates, int target,int sum,set<vector<int>>&s,int i,int n,vector<int>& temp){
        if(i==n or sum>target) return;
        if(sum==target) s.insert(temp);
        temp.push_back(candidates[i]);
        fun(candidates,target,sum+candidates[i],s,i,n,temp);
        temp.pop_back();
        fun(candidates,target,sum,s,i+1,n,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>s;
        vector<int>temp;
        fun(candidates,target,0,s,0,candidates.size(),temp);
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};